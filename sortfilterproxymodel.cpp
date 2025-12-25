#include "sortfilterproxymodel.h"

// forwards
namespace SortFilterProxyModelQmlNamspace {

void registerFiltersTypes();
void registerProxyRoleTypes();
void registerQQmlSortFilterProxyModelTypes();
void registerSorterTypes();

}

void SortFilterProxyModel::registerQml()
{
    SortFilterProxyModelQmlNamspace::registerFiltersTypes();
    SortFilterProxyModelQmlNamspace::registerProxyRoleTypes();
    SortFilterProxyModelQmlNamspace::registerQQmlSortFilterProxyModelTypes();
    SortFilterProxyModelQmlNamspace::registerSorterTypes();
}
