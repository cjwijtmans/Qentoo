#include "PortageParser.hpp"

#include <QDebug>
#include <QProcess>
#include <QStringList>
#include <QTextStream>

PortageParser::PortageParser()
{
}

PortageParser::EnvironmentalVariables PortageParser::getEnvironmentalVariables() const
{
    QProcess process;
    process.start("emerge --info", QProcess::ReadOnly);
    process.waitForFinished();
    QTextStream info(process.readAllStandardOutput());
    process.close();
    EnvironmentalVariables envars;
    while(!info.atEnd())
    {
        QString str = info.readLine();
        envars.insert(str.section('=', 0, 0, QString::SectionSkipEmpty), str.section('"', 1, 1, QString::SectionSkipEmpty));
    }
    return envars;
}

PortageParser::Repositories PortageParser::getRepositories() const
{
    EnvironmentalVariables envars = getEnvironmentalVariables();
    Repositories repositories = Repositories::fromList(envars.value("PORTDIR_OVERLAY").split(' ', QString::SkipEmptyParts));
    repositories.insert(envars.value("PORTDIR"));
    return repositories;
}
