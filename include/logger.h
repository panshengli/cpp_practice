 
#ifndef __LOGGER__
#define __LOGGER__
 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdint.h>
 
///
/// \brief 日志文件的类型
///
typedef enum log_rank {
    INFO,
    WARNING,
    ERROR,
    FATAL
}log_rank_t;
 
///
/// \brief 初始化日志文件
/// \param info_log_filename 信息文件的名字
/// \param warn_log_filename 警告文件的名字
/// \param error_log_filename 错误文件的名字
void initLogger(const std::string&info_log_filename,
                const std::string&warn_log_filename,
                const std::string&error_log_filename);
 
///
/// \brief 日志系统类
///
class Logger {
    friend void initLogger(const std::string& info_log_filename,
                           const std::string& warn_log_filename,
                           const std::string& erro_log_filename);
 
public:
    //构造函数
    Logger(log_rank_t log_rank) : m_log_rank(log_rank) {};
 
    ~Logger();
    ///
    /// \brief 写入日志信息之前先写入的源代码文件名, 行号, 函数名
    /// \param log_rank 日志的等级
    /// \param line 日志发生的行号
    /// \param function 日志发生的函数
    static std::ostream& start(log_rank_t log_rank,
                               const int line,
                               const std::string& function);
 
private:
    ///
    /// \brief 根据等级获取相应的日志输出流
    ///
    static std::ostream& getStream(log_rank_t log_rank);
 
    static std::ofstream m_info_log_file;                   ///< 信息日子的输出流
    static std::ofstream m_warn_log_file;                  ///< 警告信息的输出流
    static std::ofstream m_error_log_file;                  ///< 错误信息的输出流
    log_rank_t m_log_rank;                             ///< 日志的信息的等级
};
 
 
///
/// \brief 根据不同等级进行用不同的输出流进行读写
///
 
#define LOG(log_rank)   \
Logger(log_rank).start(log_rank, __LINE__,__FUNCTION__)
 
 
// #define CHECK(a)                                          \
// if(!(a)) {                                              \
//        LOG(ERROR) << " CHECK failed " << endl              \
//                    << #a << "= " << (a) << endl;          \
//        abort();                                            \
//    }                                                      \
// #define CHECK_NOTNULL(a)                                    \
//    if( NULL == (a)) {                                      \
//        LOG(ERROR) << " CHECK_NOTNULL failed "              \
//                    << #a << "== NULL " << endl;           \
//        abort();                                            \
//     }
 
// #define CHECK_NULL(a)                                       \
//    if( NULL != (a)) {                                      \
//        LOG(ERROR) << " CHECK_NULL failed " << endl         \
//                    << #a << "!= NULL " << endl;           \
//        abort();                                            \
//     }
 
 
// #define CHECK_EQ(a, b)                                      \
//    if(!((a) == (b))) {                                     \
//        LOG(ERROR) << " CHECK_EQ failed "  << endl          \
//                    << #a << "= " << (a) << endl           \
//                    << #b << "= " << (b) << endl;          \
//        abort();                                            \
//     }
 
// #define CHECK_NE(a, b)                                      \
//    if(!((a) != (b))) {                                     \
//        LOG(ERROR) << " CHECK_NE failed " << endl           \
//                    << #a << "= " << (a) << endl           \
//                    << #b << "= " << (b) << endl;          \
//        abort();                                            \
//     }
 
// #define CHECK_LT(a, b)                                      \
//    if(!((a) < (b))) {                                      \
//        LOG(ERROR) << " CHECK_LT failed "                   \
//                    << #a << "= " << (a) << endl           \
//                    << #b << "= " << (b) << endl;          \
//        abort();                                            \
//     }
 
// #define CHECK_GT(a, b)                                      \
//    if(!((a) > (b))) {                                      \
//        LOG(ERROR) << " CHECK_GT failed "  << endl          \
//                   << #a <<" = " << (a) << endl            \
//                    << #b << "= " << (b) << endl;          \
//        abort();                                            \
//     }
 
// #define CHECK_LE(a, b)                               \
// if(!((a) <= (b))) {                                  \
//        LOG(ERROR) << " CHECK_LE failed "  << endl    \
//                    << #a << "= " << (a) << endl      \
//                    << #b << "= " << (b) << endl;     \
//        abort();                                      \
//     }
 
// #define CHECK_GE(a, b)                                      \
//    if(!((a) >= (b))) {                                     \
//        LOG(ERROR) << " CHECK_GE failed "  << endl          \
//                    << #a << " = "<< (a) << endl            \
//                    << #b << "= " << (b) << endl;          \
//        abort();                                            \
//     }
 
// #define CHECK_DOUBLE_EQ(a, b)                               \
//    do {                                                    \
//        CHECK_LE((a), (b)+0.000000000000001L);              \
//        CHECK_GE((a), (b)-0.000000000000001L);              \
//     }while (0)
 
 
#endif //__LOGGER__
