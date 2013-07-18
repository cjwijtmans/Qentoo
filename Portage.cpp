#include "Portage.hpp"

#include <QDebug>
#include <QProcess>

Portage::Portage()
{
    PortageParser::Repositories repositories = m_Parser.getRepositories();
    for(PortageParser::Repositories::const_iterator iter = repositories.constBegin(); iter != repositories.constEnd(); ++iter)
    {
        Repository repository(*iter, &m_Repositories);
        m_Repositories.insert(repository.getName(), repository);
    }
}

Portage::Categories Portage::getCategories() const
{
    Categories categories;
    for(Repositories::const_iterator iter = m_Repositories.constBegin(); iter != m_Repositories.constEnd(); ++iter)
       categories.unite(iter->getParser().getCategories());
    return categories;
}

Portage::EnvironmentalVariables Portage::getEnvironmentalVariables() const
{
    return m_Parser.getEnvironmentalVariables();
}

const Portage::Repositories& Portage::getRepositories() const
{
    return m_Repositories;
}

Repository Portage::getRepository(const QString& name) const
{
    return m_Repositories.value(name);
}

