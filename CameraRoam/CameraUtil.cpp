#include "CameraUtil.h"
#include <math.h>
#include "MatrixState3D.h"
float CameraUtil::degree = 0;
float CameraUtil::yj = 30;
float CameraUtil::camera9Para[9];
float CameraUtil::tx = 0;
float CameraUtil::ty = 80;
float CameraUtil::tz = 0;
float CameraUtil::cx=0;
float CameraUtil::cy=0;
float CameraUtil::cz=0;
void CameraUtil::calCamera()
{
    //计算当前观察角度下摄像机的位置（基于俯仰角重新计算 X轴为旋转轴）
     cy = float(sin(yj*3.1415926535898 / 180)*CAMERA_R + ty);
    float cxz = float(cos(yj*3.1415926535898 / 180)*CAMERA_R);
    //（基于偏航角重新计算摄像机位置 Y轴为旋转轴）
     cx = float(sin(degree*3.1415926535898 / 180)*cxz + tx);
     cz = float(cos(degree*3.1415926535898 / 180)*cxz + tz);

    //计算当前摄像机的UP向量
    float upY = float(cos(yj*3.1415926535898 / 180));
    float upXZ = float(sin(yj*3.1415926535898 / 180));
    float upX = float(-upXZ*sin(degree*3.1415926535898 / 180));
    float upZ = float(-upXZ*cos(degree*3.1415926535898 / 180));
	//设置摄像机9矩阵
    camera9Para[0] = cx;
    camera9Para[1] = cy;
    camera9Para[2] = cz;

    camera9Para[3] = tx;
    camera9Para[4] = ty;
    camera9Para[5] = tz;

    camera9Para[6] = upX;
    camera9Para[7] = upY;
    camera9Para[8] = upZ;
}
/*
 * @param yjSpan y方向的偏移距离
 * @param cxSpan x方向的偏移距离
 * */
void CameraUtil::calCamera(float yjSpan, float cxSpan)
{
    //限制俯仰角度
    yj = yj + yjSpan;
    if(yj>=90){
        yj=90;
    }if(yj<=0){
        yj=0;
    }
    //限制偏航角角度
    degree = degree + cxSpan;
    if (degree >= 360)
    {
        degree = degree - 360;
    }
    else if (degree <= 0)
    {
        degree = degree + 360;
    }
    calCamera();
}
void CameraUtil::cameraGo(float goBack, float leftRight)
{
    float xStep = float(-goBack*sin(degree*3.1415926535898 / 180) - leftRight*sin((degree + 90)*3.1415926535898 / 180));//计算X方向位移
    float zStep = float(-goBack*cos(degree*3.1415926535898 / 180) - leftRight*cos((degree + 90)*3.1415926535898 / 180));//计算Z方向位移
    tx = tx + xStep;
    tz = tz + zStep;
    calCamera();
}

void CameraUtil::flushCameraToMatrix()
{
    //设置3D摄像机参数
    MatrixState3D::setCamera
            (
                    camera9Para[0], camera9Para[1], camera9Para[2],
                    camera9Para[3], camera9Para[4], camera9Para[5],
                    camera9Para[6], camera9Para[7], camera9Para[8]
            );
}