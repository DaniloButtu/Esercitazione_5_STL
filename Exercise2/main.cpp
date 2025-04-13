#include <iostream>
#include <PolygonalMesh.hpp>
#include <Utils.hpp>
#include <Utils.hpp>
#include <map>
#include <string>


int main()
{   
    std::string c0D_file = "Cell0Ds.csv";
    std::string c1D_file = "Cell1Ds.csv";
    std::string c2D_file = "Cell2Ds.csv";

    std::map<int, cell0D> cell0D_map;
    std::map<int, cell1D> cell1D_map;
    std::map<int, cell2D> cell2D_map;

    if (!read_cell0Ds(c0D_file, cell0D_map) || !read_cell1Ds(c1D_file, cell1D_map) || !read_cell2Ds(c2D_file, cell2D_map))
        return 1; //Code error for problem realred to import mesh data

    cell2D c=cell2D_map[30];
    std::cout<<"id: "<<c.id<<" marker: "<<c.marker<<std::endl;
    std::cout<<"vertices = [ ";
    for(unsigned int i=0; i<c.vertices.size(); i++)
        std::cout<<c.vertices[i]<<' ';
    std::cout<<']'<<std::endl;

    std::cout<<"edges = [ ";
    for(unsigned int i=0; i<c.edges.size(); i++)
        std::cout<<c.edges[i]<<' ';
    std::cout<<']'<<std::endl;



    return 0;
}
