//
// Created by Taoning Ge on 2022/6/7.
//

#ifndef CPP_BIG_HOMEWORK_UTILS_H
#define CPP_BIG_HOMEWORK_UTILS_H


#include <string>

class Utils {
public:
    /**
     * 获取系统类型
     * @return 0: Windows, 1: Linux, 2: macOS
     */
    static int getSystem();

    /**
     * 获取用户主目录
     * @return 用户主目录
     */
    static std::string getUserHome();

    /**
     * 获取文件路径
     * @return 文件路径
     */
    static std::string getFilePath();

    /**
     * 退出程序
     */
    static void exitProgram();
};


#endif //CPP_BIG_HOMEWORK_UTILS_H
