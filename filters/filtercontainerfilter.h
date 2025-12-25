#ifndef FILTERCONTAINERFILTER_H
#define FILTERCONTAINERFILTER_H

#include "filter.h"
#include "filtercontainer.h"

namespace SortFilterProxyModelQmlNamspace {

class FilterContainerFilter : public Filter, public FilterContainer {
    Q_OBJECT
    Q_INTERFACES(SortFilterProxyModelQmlNamspace::FilterContainer)
    Q_PROPERTY(QQmlListProperty<SortFilterProxyModelQmlNamspace::Filter> filters READ filtersListProperty NOTIFY filtersChanged)
    Q_CLASSINFO("DefaultProperty", "filters")

public:
    using Filter::Filter;

    void proxyModelCompleted(const QQmlSortFilterProxyModel& proxyModel) override;

Q_SIGNALS:
    void filtersChanged();

private:
    void onFilterAppended(Filter* filter) override;
    void onFilterRemoved(Filter* filter) override;
    void onFiltersCleared() override;
};

}

#endif // FILTERCONTAINERFILTER_H
