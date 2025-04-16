#include <iostream>
#include "PolygonalMesh.hpp"
#include "Utils.hpp"
#include "UCDUtilities.hpp"

using namespace std;
using namespace Eigen;
using namespace PolygonalLibrary;


int main()
{   
    Polygonal_Mesh mesh;
    
    if(!import_mesh(mesh))
    {
        cerr<<"Error: file not found"<<endl;
        return 1;
    }

    /*TEST1 to verify in all marker are well stored
     N.B. marker=0 are not stored becasuse they identify a internal cell*/
     map<unsigned int, list<unsigned int>>& m_0Ds_markers = mesh.cell0Ds_markers;
     map<unsigned int, list<unsigned int>>& m_1Ds_markers = mesh.cell1Ds_markers;
     map<unsigned int, list<unsigned int>>& m_2Ds_markers = mesh.cell2Ds_markers;

     for(auto& [marker, list_id] : m_0Ds_markers)
     {
        cout<<"Marker0D: "<<marker<<"  IDs = [";
        for(auto& id : list_id)
            cout<<' '<<id;
        cout<<" ]"<<endl;
     }

     cout<<endl;
     for(auto& [marker, list_id] : m_1Ds_markers)
     {
        cout<<"Marker1D: "<<marker<<"  IDs = [";
        for(auto& id : list_id)
            cout<<' '<<id;
        cout<<" ]"<<endl;
     }

     cout<<endl;
     for(auto& [marker, list_id] : m_2Ds_markers)
     {
        cout<<"Marker2D: "<<marker<<"  IDs = [";
        for(auto& id : list_id)
            cout<<' '<<id;
        cout<<" ]"<<endl;
     }


     /*To export the stored mesh, then using paraview i can verify if my stored mesh is equal to the input mesh (TEST4)*/
    Gedim::UCDUtilities utilities;
    utilities.ExportPoints("./Cell0Ds.inp",
                           mesh.cell0Ds_coordinates);

    utilities.ExportSegments("./Cell1Ds.inp",
                             mesh.cell0Ds_coordinates,
                             mesh.cell1Ds_extrema);
    


    return 0;
}
