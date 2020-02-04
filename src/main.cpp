#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/common/transforms.h>
#include <pcl/filters/passthrough.h>
#include <pcl/compression/octree_pointcloud_compression.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>

#include <iostream>
#include <string>
#include <pcl/filters/voxel_grid.h>
#include <pcl/point_types.h>

#include <iostream>
int main(int argc, char *argv[])
{
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr pcl_points;
    pcl_points = pcl::PointCloud<pcl::PointXYZRGB>::Ptr(new pcl::PointCloud<pcl::PointXYZRGB>());
    pcl::io::loadPLYFile(argv[1], *pcl_points);

    pcl::VoxelGrid<pcl::PointXYZRGB> sor;

    sor.setInputCloud (pcl_points);

    sor.setLeafSize (atoi(argv[3]), atoi(argv[3]), atoi(argv[3]));

    sor.filter (*pcl_points);

    for(int j=0;j<pcl_points->size();j++)
    {
        pcl_points->points[j].x = pcl_points->points[j].x/atof(argv[3]);
        pcl_points->points[j].y = pcl_points->points[j].y/atof(argv[3]);
        pcl_points->points[j].z = pcl_points->points[j].z/atof(argv[3]);
    }

    pcl::io::savePLYFileASCII(argv[2], *pcl_points);
}

