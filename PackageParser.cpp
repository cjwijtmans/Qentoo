#include "PackageParser.hpp"

PackageParser::PackageParser()
{
}

PackageParser::PackageParser(const QDir& dir)
    :m_Dir(dir)
{
}

PackageParser::PackageParser(const QString& dir)
    :m_Dir(dir)
{
}
