#ifndef _SENSAUR_DEVICE_H_
#define _SENSAUR_DEVICE_H_
#include "Arduino.h"


#define MAX_COMPONENT_COUNT 6


class Component {
public:
	Component();
	void setInfo(const char *info);
	String infoJson();
private:

	// we keep the info string in unparsed form, since otherwise it would take a lot of memory; could reconsider this (the ESP32 probably has plenty of RAM)
	char m_info[64];  // e.g. i,CO2,K-30,PPM
};



class Device {
public:
	Device();

	// basic device attributes
	inline const char *id() const { return m_id; }
	void setId(const char *id);
	inline const char *version() const { return m_version; }
	void setVersion(const char *version);

	// current status
	inline uint32_t lastMessageTime() const { return m_lastMessageTime; }
	inline void setLastMessageTime(uint32_t lastMessageTime) { m_lastMessageTime = lastMessageTime; }
	inline bool connected() const { return m_connected; }
	inline void setConnected(bool connected) { m_connected = connected; }

	// component access
	inline int componentCount() const { return m_componentCount; }
	inline void setComponentCount(int componentCount) { m_componentCount = (componentCount < MAX_COMPONENT_COUNT) ? componentCount : MAX_COMPONENT_COUNT; }
	inline Component &component(int index) { return m_components[index]; }
	inline void resetComponents() { m_componentCount = 0; }

private:
	char m_version[10];
	char m_id[10];
	uint32_t m_lastMessageTime;
	bool m_connected;
	int m_componentCount;
	Component m_components[MAX_COMPONENT_COUNT];
};


#endif  // _SENSAUR_DEVICE_H_
