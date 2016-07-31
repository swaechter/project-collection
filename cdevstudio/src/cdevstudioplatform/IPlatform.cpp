#include "IPlatform.h"

IPlatform *IPlatform::m_IPlatform = nullptr;

IPlatform::IPlatform(QObject *parent) : QObject(parent)
{
	m_IPlatform = this;
}

IPlatform *IPlatform::getInstance()
{
	return m_IPlatform;
}
