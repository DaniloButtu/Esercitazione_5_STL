#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


bool read_cell0Ds(const std::string& file_name, std::map<int, cell0D>& cell0D_map){
    std::ifstream ifile(file_name);

    if (ifile.fail()){
        std::cerr<<"Error: failed to open the file "<<file_name<<std::endl;
        return false;
    }

    //Discard the header of the file
    std::string line;
    getline(ifile, line);

    while (getline(ifile, line)){
        std::stringstream ss_line(line);
        char delimiter; // to storage the delimiter ';'
        cell0D cell;

        //Id;Marker;X;Y
        ss_line>>cell.id>>delimiter;
        ss_line>>cell.marker>>delimiter;
        ss_line>>cell.x>>delimiter>>cell.y;

        cell0D_map[cell.id] = cell;

    }

    return true;
};


bool read_cell1Ds(const std::string& file_name, std::map<int, cell1D>& cell1D_map){
    std::ifstream ifile(file_name);

    if (ifile.fail()){
        std::cerr<<"Error: failed to open the file "<<file_name<<std::endl;
        return false;
    }

    
    //Discard the header of the file
    std::string line;
    getline(ifile, line);

    while (getline(ifile, line)){
        std::stringstream ss_line(line);
        char delimiter; // to storage the delimiter ';'
        cell1D cell;

        //Id;Marker;Origin;End
        ss_line>>cell.id>>delimiter;
        ss_line>>cell.marker>>delimiter;
        ss_line>>cell.origin>>delimiter>>cell.end;

        cell1D_map[cell.id] = cell;

    }

    return true;
};


bool read_cell2Ds(const std::string& file_name, std::map<int, cell2D>& cell2D_map){
    std::ifstream ifile(file_name);
    if (ifile.fail()){
        std::cerr<<"Error: failed to open the file "<<file_name<<std::endl;
    }

    //Discard the header
    std::string line;
    getline(ifile, line);

    while (getline(ifile, line)){
        std::stringstream ss_line(line);
        char delimiter; //to storage the delimiter ';'
        cell2D cell;

        //Id;Marker;NumVertices;Vertices;NumEdges;Edges
        ss_line>>cell.id>>delimiter;
        ss_line>>cell.marker>>delimiter;

        size_t num_vert;
        ss_line>>num_vert>>delimiter;
        for(unsigned int i=0; i<num_vert; i++){
            int vert_id;
            ss_line>>vert_id>>delimiter;
            cell.vertices.push_back(vert_id);
        }

        size_t num_edges;
        ss_line>>num_edges>>delimiter;
        for(unsigned int i=0; i<num_edges; i++){
            int edge_id;
            ss_line>>edge_id>>delimiter;
            cell.edges.push_back(edge_id);
        }

        cell2D_map[cell.id] = cell;

    }

    return true;
}