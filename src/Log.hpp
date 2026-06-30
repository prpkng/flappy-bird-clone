#pragma once

#include <spdlog/spdlog.h>

class Log
{
public:
	Log();
	~Log();

	inline std::shared_ptr<spdlog::logger>& GetClientLogger() { return m_ClientLogger; }

	static Log& Instance();

private:
	std::shared_ptr<spdlog::logger> m_ClientLogger;
};

#define LOG_FATAL(...)     SPDLOG_LOGGER_CRITICAL(::Log::Instance().GetClientLogger(), __VA_ARGS__); __debugbreak()
#define LOG_ERROR(...)     SPDLOG_LOGGER_ERROR(::Log::Instance().GetClientLogger(), __VA_ARGS__)
#define LOG_WARN(...)      SPDLOG_LOGGER_WARN(::Log::Instance().GetClientLogger(), __VA_ARGS__)
#define LOG_INFO(...)      SPDLOG_LOGGER_INFO(::Log::Instance().GetClientLogger(), __VA_ARGS__)
#define LOG_TRACE(...)     SPDLOG_LOGGER_TRACE(::Log::Instance().GetClientLogger(), __VA_ARGS__)