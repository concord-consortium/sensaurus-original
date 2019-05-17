#include "SensaurDevice.h"


// ======== COMPONENT CLASS ========


Component::Component() {
	m_info[0] = 0;
}


void Component::setInfo(const char *info) {
	strncpy(m_info, info, 64);
}


String Component::infoJson() {
	return "";
}


// ======== DEVICE CLASS ========



Device::Device() {
	m_id[0] = 0;
	m_version[0] = 0;
	m_connected = false;
	m_componentCount = 0;
}


void Device::setId(const char *id) {
	strncpy(m_id, id, 10);
}


void Device::setVersion(const char *version) {
	strncpy(m_version, version, 10);
}
