 
#include <cstdlib>
#include <ctime>
#include "logger.h"
 
std::ofstream Logger::m_error_log_file;
std::ofstream Logger::m_info_log_file;
std::ofstream Logger::m_warn_log_file;
 
void initLogger(const std::string&info_log_filename,
                const std::string&warn_log_filename,
                const std::string&error_log_filename){
    Logger::m_info_log_file.open(info_log_filename.c_str());
    Logger::m_warn_log_file.open(warn_log_filename.c_str());
    Logger::m_error_log_file.open(error_log_filename.c_str());
}
 
std::ostream& Logger::getStream(log_rank_t log_rank){
    return (INFO == log_rank) ?
           (m_info_log_file.is_open() ?m_info_log_file : std::cout) :
           (WARNING == log_rank ?
            (m_warn_log_file.is_open()? m_warn_log_file : std::cerr) :
            (m_error_log_file.is_open()? m_error_log_file : std::cerr));
}
 
std::ostream& Logger::start(log_rank_t log_rank,
                            const int line,
                            const std::string&function)
{
    time_t tm;
    time(&tm);
    char* time_string;
//    ctime_r(&tm, time_string);
    return getStream(log_rank) << "[" << __FILE__/*<< time_string*/
                               << ", " << function << ", "
                               << line<<"]: "
                               <<std::flush;
}
 
Logger::~Logger(){
    getStream(m_log_rank) << std::endl << std::flush;
 
    if (FATAL == m_log_rank) {
        m_info_log_file.close();
        m_info_log_file.close();
        m_info_log_file.close();
        abort();
    }
}
