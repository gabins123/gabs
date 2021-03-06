#include "gpch.h"

#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace GabsEngine
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$ ");
		s_CoreLogger = spdlog::stdout_color_mt("Gabs");
		s_CoreLogger->set_level(spdlog::level::trace);

		spdlog::set_pattern("%^[%T] %n: %v%$ ");
		s_ClientLogger = spdlog::stdout_color_mt("App");
	}
}