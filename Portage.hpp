#ifndef PORTAGE_HPP
#define PORTAGE_HPP

#include <QString>

#include "PortageParser.hpp"
#include "Repository.hpp"

class Portage
{
public:
    typedef PortageParser::EnvironmentalVariables EnvironmentalVariables;
    typedef Repository::Categories Categories;
    typedef Repository::Packages Packages;
    typedef Repository::Repositories Repositories;

    Portage();
    Categories getCategories() const;
    EnvironmentalVariables getEnvironmentalVariables() const;
    Packages getPackages(QString strCategory) const;
    const PortageParser& getParser() const;
    const Repositories& getRepositories() const;
    Repository getRepository(const QString& name) const;

private:
    PortageParser   m_Parser;
    Repositories    m_Repositories;
};

#endif // PORTAGE_HPP
