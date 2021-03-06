#include "custom_cpu_widget.h"
#include "custom_cpu_widgetplugin.h"

#include <QtPlugin>

custom_cpu_widgetPlugin::custom_cpu_widgetPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void custom_cpu_widgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool custom_cpu_widgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *custom_cpu_widgetPlugin::createWidget(QWidget *parent)
{
    return new custom_cpu_widget(parent);
}

QString custom_cpu_widgetPlugin::name() const
{
    return QLatin1String("custom_cpu_widget");
}

QString custom_cpu_widgetPlugin::group() const
{
    return QLatin1String("Example Custom Widgets");
}

QIcon custom_cpu_widgetPlugin::icon() const
{
    return QIcon();
}

QString custom_cpu_widgetPlugin::toolTip() const
{
    return QLatin1String("Custom CPU Widget");
}

QString custom_cpu_widgetPlugin::whatsThis() const
{
    return QLatin1String("This is a CPU USED Custom Widget");
}

bool custom_cpu_widgetPlugin::isContainer() const
{
    return false;
}

QString custom_cpu_widgetPlugin::domXml() const
{
    return QLatin1String("<widget class=\"custom_cpu_widget\" name=\"custom_cpu_widget\">\n</widget>\n");
}

QString custom_cpu_widgetPlugin::includeFile() const
{
    return QLatin1String("custom_cpu_widget.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(custom_cpu_widgetplugin, custom_cpu_widgetPlugin)
#endif // QT_VERSION < 0x050000
