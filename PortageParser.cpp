#include "PortageParser.hpp"

#include <QDebug>
#include <QProcess>
#include <QStringList>
#include <QTextStream>

PortageParser::PortageParser()
{
    QProcess process;
    process.start("emerge --info", QProcess::ReadOnly);
    process.waitForFinished();
    QTextStream info(process.readAllStandardOutput());
    while(!info.atEnd())
    {
        QString str = info.readLine();
        m_EnvironmentalVariables.insert(str.section('=', 0, 0, QString::SectionSkipEmpty), str.section('"', 1, 1, QString::SectionSkipEmpty));
    }
}

PortageParser::EnvironmentalVariables PortageParser::getEnvironmentalVariables() const
{
    return m_EnvironmentalVariables;
}

PortageParser::Repositories PortageParser::getRepositories() const
{
    Repositories strlRepositories = m_EnvironmentalVariables.value("PORTDIR_OVERLAY").split(' ', QString::SkipEmptyParts);
    strlRepositories.append(m_EnvironmentalVariables.value("PORTDIR"));
    return strlRepositories;
}
