/* This file is generated by genxml. */
/* No manual modification is permitted. */

#pragma once

#include <vector>
#include <string>
#include <stdint.h>
#include "tinyxml.h"

#define LOG_DEBUG
#define LOG_ERROR







class CMsgLoader
{
public:
	struct STMsg
	{
		STMsg()
		{

		}

		struct STConfig
		{
			STConfig()
			{

				m_iclientregid = 0;

				m_strkey.clear();

				m_iport = 0;

				m_strproto.clear();

				m_strregkey.clear();

				m_iserverregid = 0;

			}

			int32_t m_iclientregid;

			std::string m_strkey;

			int32_t m_iport;

			std::string m_strproto;

			std::string m_strregkey;

			int32_t m_iserverregid;


		};

		STConfig m_STConfig;
		struct STMsgId
		{
			STMsgId()
			{

				m_iid = 0;

				m_strname.clear();

			}

			int32_t m_iid;

			std::string m_strname;


		};


		std::vector<STMsgId> m_vecSTMsgId;

	};

	const STMsg & GetMsg()
	{
		return m_STMsg;
	}

	bool LoadCfg(const std::string & file)
	{
		TiXmlDocument document;
		if (!document.LoadFile((const char*)file.c_str()))
		{
			LOG_ERROR("CMsgLoader::LoadCfg(%s) failed", (const char*)file.c_str());
			return false;
		}

		TiXmlElement* pMsg = document.RootElement();
		if (!pMsg)
		{
			LOG_ERROR("document.RootElement failed");
			return false;
		}

		// clear
		STMsg tmp;
		m_STMsg = tmp;




		TiXmlNode * pConfig = pMsg->FirstChild("Config");
		if (pConfig)
		{

			STMsg::STConfig tmpConfig;

			((TiXmlElement *)pConfig)->Attribute("clientregid", &tmpConfig.m_iclientregid);
			LOG_DEBUG("        clientregid %d", tmpConfig.m_iclientregid);

			tmpConfig.m_strkey = ((TiXmlElement *)pConfig)->Attribute("key");
			LOG_DEBUG("        key %s", tmpConfig.m_strkey.c_str());

			((TiXmlElement *)pConfig)->Attribute("port", &tmpConfig.m_iport);
			LOG_DEBUG("        port %d", tmpConfig.m_iport);

			tmpConfig.m_strproto = ((TiXmlElement *)pConfig)->Attribute("proto");
			LOG_DEBUG("        proto %s", tmpConfig.m_strproto.c_str());

			tmpConfig.m_strregkey = ((TiXmlElement *)pConfig)->Attribute("regkey");
			LOG_DEBUG("        regkey %s", tmpConfig.m_strregkey.c_str());

			((TiXmlElement *)pConfig)->Attribute("serverregid", &tmpConfig.m_iserverregid);
			LOG_DEBUG("        serverregid %d", tmpConfig.m_iserverregid);



			m_STMsg.m_STConfig = tmpConfig;
		}
		for (TiXmlNode * pMsgId = pMsg->FirstChild("MsgId"); NULL != pMsgId; pMsgId = pMsgId->NextSibling("MsgId"))
		{

			STMsg::STMsgId tmpMsgId;

			((TiXmlElement *)pMsgId)->Attribute("id", &tmpMsgId.m_iid);
			LOG_DEBUG("        id %d", tmpMsgId.m_iid);

			tmpMsgId.m_strname = ((TiXmlElement *)pMsgId)->Attribute("name");
			LOG_DEBUG("        name %s", tmpMsgId.m_strname.c_str());



			m_STMsg.m_vecSTMsgId.push_back(tmpMsgId);
		}

		return true;
	}

private:
	STMsg m_STMsg;
};


