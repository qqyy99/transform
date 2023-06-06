#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>

int main() {
    // 定义一个点在世界坐标系中的坐标P_w
    Eigen::Vector4f P_w(1.0, 2.0, 3.0, 1.0);

    // 定义机器人在世界坐标系中的位置t_wr
    Eigen::Vector3f t_wr(4.0, 5.0, 6.0);

    // --------- 开始你的代码	---------------//
    
    // 构建旋转矩阵R_wc
    Eigen::AngleAxisd rotation_vector1 (M_PI/4, Eigen::Vector3d (1, 0, 0));
    Eigen::AngleAxisd rotation_vector2 (M_PI/6, Eigen::Vector3d (0, 1, 0));
    Eigen::AngleAxisd rotation_vector;
    rotation_vector = rotation_vector2 * rotation_vector1;

    Eigen::Matrix3d Rwc = rotation_vector.toRotationMatrix();
   
    // 构建变换矩阵T_wc
    Eigen::Matrix4f T_wc = Eigen::Matrix4f::Identity();
    T_wc.topLeftCorner(3,3) = Rwc.cast<float>();
    T_wc.topRightCorner(3,1) = t_wr;

    // 计算点在机器人坐标系中的坐标P_c = T_cw * P_w
    Eigen::Vector4f P_c = T_wc.inverse().cast<float>() * P_w;

    // --------- 结束你的代码	---------------//

    std::cout << "The point in the robot coordinate system is: \n" << P_c << std::endl;

    return 0;
}
