#ifndef PORTAGEPARSER_HPP
#define PORTAGEPARSER_HPP

#include <QDir>
#include <QMap>
#include <QStringList>

class PortageParser
{
public:
    typedef QMap<QString, QString> EnvironmentalVariables;
    typedef QStringList Repositories;

    PortageParser();
    EnvironmentalVariables getEnvironmentalVariables() const;
    Repositories getRepositories() const;

private:
    EnvironmentalVariables m_EnvironmentalVariables;
};

#endif // PORTAGEPARSER_HPP
