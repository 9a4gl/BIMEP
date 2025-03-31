#ifndef BIMEPDEFINITION_H
#define BIMEPDEFINITION_H

#include <vector>

struct Point;
struct Link;

class BIMEPDefinition
{
public:
    static BIMEPDefinition* create(int year);
    static BIMEPDefinition* get();

    static const std::vector<Link>& links();
    static const std::vector<Point>& points();

private:
    BIMEPDefinition();

    static BIMEPDefinition* m_instance;

    int m_year = 0;
    std::vector<Link> m_links;
    std::vector<Point> m_points_2024;
    std::vector<Point> m_points_2025;
};

#endif // BIMEPDEFINITION_H
