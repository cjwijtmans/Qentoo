#ifndef PACKAGEPARSER_HPP
#define PACKAGEPARSER_HPP

#include <QDir>
#include <QString>

class PackageParser
{
public:
    PackageParser();
    PackageParser(const QDir& dir);
    PackageParser(const QString& dir);

private:
    QDir m_Dir;
};

#endif // PACKAGEPARSER_HPP
