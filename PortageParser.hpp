#ifndef PORTAGEPARSER_HPP
#define PORTAGEPARSER_HPP

#include <QDir>
#include <QMap>
#include <QSet>
#include <QString>

class PortageParser
{
public:
    typedef QMap<QString, QString> EnvironmentalVariables;
    typedef QSet<QString> Repositories;

    PortageParser();
    EnvironmentalVariables getEnvironmentalVariables() const;
    Repositories getRepositories() const;

private:
    EnvironmentalVariables m_EnvironmentalVariables;
};

#endif // PORTAGEPARSER_HPP
