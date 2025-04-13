#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>



/*Create a struct to modelize points, edges and polygons*/
struct cell0D{
    int id;
    int marker;
    double x, y;
};

struct cell1D{
    int id;
    int marker;
    int origin;
    int end;
};

struct cell2D{
    int id;
    int marker;
    std::vector<int> vertices; //it reference to cellOD id
    std::vector<int> edges; //it reference to cell1D id
};



/*Function that read the data of cell0D and storage them into a map
file_name: file that contains the data
cell0D_map: map in which store the OD data */
bool read_cell0Ds(const std::string& file_name, std::map<int, cell0D>& cell0D_map);

/*Function that read the data of cell1D and storage them into a map
file_name: file that contains the data
cell0D_map: map in which store the 1D data */
bool read_cell1Ds(const std::string& file_name, std::map<int, cell1D>& cell1D_map);

/*Function that read the data of cell1D and storage them into a map
file_name: file that contains the data
cell0D_map: map in which store the 2D data */
bool read_cell2Ds(const std::string& file_name, std::map<int, cell2D>& cell2D_map);