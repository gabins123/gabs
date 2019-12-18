#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace GabsEngine
{
	class GABS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> Log::GetCoreLogger(){ return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger> Log::GetClientLogger(){ return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
		static std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	};
}

//Engine Log
#define CORE_LOG(...) ::GabsEngine::Log::GetCoreLogger() -> info(__VA_ARGS__)
#define CORE_LOGWARNING(...) ::GabsEngine::Log::GetCoreLogger() -> warn(__VA_ARGS__)
#define CORE_LOGERROR(...) ::GabsEngine::Log::GetCoreLogger() -> error(__VA_ARGS__)


//Client Log
#define CLIENT_LOG(...) ::GabsEngine::Log::GetClientLogger()-> info(__VA_ARGS__)
#define CLIENT_LOGWARNING(...) ::GabsEngine::Log::GetClientLogger() -> warn(__VA_ARGS__)
#define CLIENT_LOGERROR(...) ::GabsEngine::Log::GetClientLogger() -> error(__VA_ARGS__)
