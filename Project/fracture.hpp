#ifndef FRACTURE_HPP
#define FRACTURE_HPP

#include <Eigen/Eigen>
#include <vector>
#include <string>

using namespace std;

struct Vertex {
    double x;
    double y;
    double z;
};

struct Fracture {
    int id;
    int numVertices;
    vector<Vertex> vertices;
};

struct Trace {
    int traceId;
    int fractureId1;
    int fractureId2;
    Vertex start;
    Vertex end;
    bool tips1;
    bool tips2;
    double length;
};

struct Plane {
    Vertex normal;
    double d;
};

struct Projection {
    double min;
    double max;
};

vector<Fracture> readFractures(const string &filename);

bool fractureIntersection(const Fracture& f1, const Fracture& f2);
Plane calculatePlane(const Fracture& fracture);
vector<Vertex> findIntersectionLine(const Plane& p1, const Plane& p2);
Vertex lineEdgeIntersection(const Vertex& point, const Vertex& direction, const Vertex& v1, const Vertex& v2);
vector<Vertex> getMiddlePoints (const Vertex& point, const Vertex& direction, const Vertex& v1, const Vertex& v2, const Vertex& v3, const Vertex& v4);

vector<Trace> computeTraces(const vector<Fracture> &fractures);

void writeTraces(const vector<Trace>& traces, const string& filename);
void classifyAndWriteTracesByFracture(const vector<Fracture>& fractures, const vector<Trace>& traces, const string& filename);

#endif // FRACTURE_HPP
