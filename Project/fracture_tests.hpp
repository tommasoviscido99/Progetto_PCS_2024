#ifndef FRACTURE_TESTS_HPP
#define FRACTURE_TESTS_HPP

#include <gtest/gtest.h>
#include "fracture.hpp"
#include <cmath>

bool compareVertices(const Vertex& v1, const Vertex& v2) {
    return fabs(v1.x - v2.x) < 1e-6 && fabs(v1.y - v2.y) < 1e-6 && fabs(v1.z - v2.z) < 1e-6;
}

TEST(FractureTest, FractureIntersection) {
    Fracture f1 = {1, 4, {{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}}};
    Fracture f2 = {2, 4, {{0.5, 0.5, -1}, {0.5, 0.5, 1}, {0.5, -0.5, 1}, {0.5, -0.5, -1}}};

    ASSERT_TRUE(fractureIntersection(f1, f2));
}

TEST(FractureTest, CalculatePlane) {
    Fracture f = {1, 4, {{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}}};

    Plane p = calculatePlane(f);

    ASSERT_EQ(p.normal.x, 0);
    ASSERT_EQ(p.normal.y, 0);
    ASSERT_EQ(p.normal.z, 1);
    ASSERT_EQ(p.d, 0);
}

TEST(PlaneTest, FindIntersectionLine) {
    Plane p1{{0, 0, 1}, 0};
    Plane p2{{1, 0, 0}, 0};
    vector<Vertex> result = findIntersectionLine(p1, p2);
    vector<Vertex> expected{{0, 0, 0}, {0, 1, 0}};
    ASSERT_TRUE(compareVertices(result[0], expected[0]));
    ASSERT_TRUE(compareVertices(result[1], expected[1]));
}

TEST(IntersectionTest, LineEdgeIntersection) {
    Vertex point{0, 0, 0};
    Vertex direction{1, 0, 0};
    Vertex v1{0, 0, 0};
    Vertex v2{1, 1, 0};
    Vertex expected{0, 0, 0};
    Vertex result = lineEdgeIntersection(point, direction, v1, v2);
    ASSERT_TRUE(compareVertices(result, expected));
}

TEST(MiddlePointsTest, GetMiddlePoints) {
    Vertex point{0, 0, 0};
    Vertex direction{1, 0, 0};
    Vertex v1{1, 0, 0};
    Vertex v2{2, 0, 0};
    Vertex v3{3, 0, 0};
    Vertex v4{4, 0, 0};
    vector<Vertex> result = getMiddlePoints(point, direction, v1, v2, v3, v4);
    vector<Vertex> expected{{2, 0, 0}, {3, 0, 0}};
    ASSERT_TRUE(compareVertices(result[0], expected[0]));
    ASSERT_TRUE(compareVertices(result[1], expected[1]));
}

#endif // FRACTURE_TESTS_HPP
