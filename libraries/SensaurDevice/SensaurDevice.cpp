#include "SensaurDevice.h"
#include "ArduinoJson.h"


// ======== COMPONENT CLASS ========


Component::Component() {
	m_dir = 0;
	m_type[0] = 0;
	m_model[0] = 0;
	m_units[0] = 0;
	m_value[0] = 0;
}


void Component::setValue(const char *value) {
	strncpy(m_value, value, 10);
}


void Component::setInfo(const char *info) {
	m_dir = info[0];
	int part = 0;
	int pos = 0;
	while (info[pos]) {
		if (info[pos] == ',') {
			part++;
			switch (part) {
			case 1: strncpy(m_type, info + 1, 20); break;
			case 2: strncpy(m_model, info + 1, 20); break;
			case 3: strncpy(m_units, info + 1, 20); break;
			}
		}
		pos++;
	}
	strncpy(m_idSuffix, m_type, 6);  // use first 5 characters of type
}


String Component::infoJson() {
	DynamicJsonDocument doc(256);
	doc["dir"] = m_dir;
	doc["type"] = m_type;
	doc["model"] = m_model;
	doc["units"] = m_units;
	String message;
	serializeJson(doc, message);
	return message;
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
