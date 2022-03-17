#include "include/dbscan.h"

vector<Point> DBSCAN::run() {

    int cluster_id = 0;
    
    vector<Point>::iterator db_iter;
    for(db_iter = pts.begin(); db_iter != pts.end(); db_iter++) {

        if(db_iter->cluster_id == UNCLASSIFIED) {

            if(expandCluster(*db_iter, cluster_id) == true) {
                cluster_id += 1;
            }
    
        }
    }
    
    return pts;
}

int DBSCAN::proposed() {

    int cluster_id = 0;
    
    vector<Point>::iterator db_iter;
    for(db_iter = pts.begin(); db_iter != pts.end(); db_iter++) {

        if(db_iter->cluster_id == UNCLASSIFIED) {

            if(proposedExpand(*db_iter, cluster_id) == true) {
                cluster_id += 1;
            }
    
        }
    }
    
    return 0;
}

int DBSCAN::revised() {

    int cluster_id = 0;
    
    vector<Point>::iterator db_iter;
    for(db_iter = pts.begin(); db_iter != pts.end(); db_iter++) {

        if(db_iter->cluster_id == UNCLASSIFIED) {

            if(expandCluster(*db_iter, cluster_id) == true) {
                cluster_id += 1;
            }
    
        }
    }

    for(db_iter = pts.begin(); db_iter != pts.end(); db_iter++) {

        if(db_iter->cluster_id == BORDER) {

            float lowest = eps;
            vector<int> border_neighbors = regionQuery(*db_iter);

            vector<int>::iterator bn_iter;
            for(bn_iter = border_neighbors.begin(); bn_iter != border_neighbors.end(); bn_iter++) {
                
                if(pts.at(*bn_iter).cluster_id == CORE) {
                    // float distance = distanceMeasure(pts.at(*bn_iter), *db_iter);
                    if(distanceMeasure(pts.at(*bn_iter), *db_iter) < lowest) {
                        lowest = distanceMeasure(pts.at(*bn_iter), *db_iter);
                        db_iter->cluster_id = pts.at(*bn_iter).cluster_id;
                    }
                }

            }
        }
    }
    
    return 0;
}

bool DBSCAN::expandCluster(Point point, int cluster_id) {
    
    vector<int> cluster_seeds = regionQuery(point);

    if(cluster_seeds.size() < min_pts) {
        point.cluster_id = NOISE;
        return false;
    } 
    else {
        int index = 0, index_core = 0;
        point.cluster_id = CORE;
        
        vector<int>::iterator seeds_iter;
        for(seeds_iter = cluster_seeds.begin(); seeds_iter != cluster_seeds.end(); seeds_iter++) {

            pts.at(*seeds_iter).cluster_id = cluster_id;

            if(pts.at(*seeds_iter).point == point.point) {
                index_core = index;
            }
            index++;
        }

        cluster_seeds.erase(cluster_seeds.begin() + index_core);

        vector<int>::size_type i, n;
        for(i = 0, n = cluster_seeds.size(); i < n; i++) {
            vector<int> cluster_neighbors = regionQuery(pts.at(cluster_seeds[i]));

            if(cluster_neighbors.size() >= min_pts) {
                
                pts.at(cluster_seeds[i]).cluster_id = CORE;
                vector<int>::iterator neighbors_iter;
                for(neighbors_iter = cluster_neighbors.begin(); neighbors_iter != cluster_neighbors.end(); neighbors_iter++) {
                    
                    if(pts.at(*neighbors_iter).cluster_id == UNCLASSIFIED ||
                        pts.at(*neighbors_iter).cluster_id == NOISE) {

                            if(pts.at(*neighbors_iter).cluster_id == UNCLASSIFIED) {
                                cluster_seeds.push_back(*neighbors_iter);
                                n = cluster_seeds.size();
                            } else {
                                pts.at(*neighbors_iter).cluster_id = BORDER;
                            }
                            pts.at(*neighbors_iter).cluster_id = cluster_id;
                    }
                }
            } else {
                pts.at(cluster_seeds[i]).cluster_id = BORDER;
            }
        }

        return true;
    }
}

bool DBSCAN::proposedExpand(Point point, int cluster_id) {
    
    vector<int> cluster_seeds = regionQuery(point);

    if(cluster_seeds.size() < min_pts) {
        point.cluster_id = NOISE;
        return false;
    } 
    else {
        int index = 0, index_core = 0;
        point.cluster_id = CORE;
        
        vector<int>::iterator seeds_iter;
        for(seeds_iter = cluster_seeds.begin(); seeds_iter != cluster_seeds.end(); seeds_iter++) {

            pts.at(*seeds_iter).cluster_id = cluster_id;

            if(pts.at(*seeds_iter).point == point.point) {
                index_core = index;
            }
            index++;
        }

        cluster_seeds.erase(cluster_seeds.begin() + index_core);

        vector<int>::size_type i, n;
        for(i = 0, n = cluster_seeds.size(); i < n; i++) {
            vector<int> cluster_neighbors = regionQuery(pts.at(cluster_seeds[i]));

            if(cluster_neighbors.size() >= min_pts) {
                
                pts.at(cluster_seeds[i]).cluster_id = CORE;
                vector<int>::iterator neighbors_iter;
                for(neighbors_iter = cluster_neighbors.begin(); neighbors_iter != cluster_neighbors.end(); neighbors_iter++) {
                    
                    if(pts.at(*neighbors_iter).cluster_id == UNCLASSIFIED ||
                        pts.at(*neighbors_iter).cluster_id == NOISE) {

                            if(pts.at(*neighbors_iter).cluster_id == UNCLASSIFIED) {
                                cluster_seeds.push_back(*neighbors_iter);
                                n = cluster_seeds.size();
                            } else {
                                pts.at(*neighbors_iter).cluster_id = BORDER;
                                pts.at(*neighbors_iter).closest_core = distanceMeasure(pts.at(*neighbors_iter), pts.at(cluster_seeds[i]));
                            }
                            pts.at(*neighbors_iter).cluster_id = cluster_id;
                    }

                    if(pts.at(*neighbors_iter).cluster_id == BORDER) {
                        float temp_dist = distanceMeasure(pts.at(*neighbors_iter), pts.at(cluster_seeds[i]));
                        if(pts.at(*neighbors_iter).closest_core > temp_dist) {
                            pts.at(*neighbors_iter).closest_core = temp_dist;
                            pts.at(*neighbors_iter).cluster_id = pts.at(cluster_seeds[i]).cluster_id;
                        }
                    }
                }
            } else {
                pts.at(cluster_seeds[i]).cluster_id = BORDER;
                pts.at(cluster_seeds[i]).closest_core = distanceMeasure(pts.at(cluster_seeds[i]), pts.at(*seeds_iter));
            }
        }

        return true;
    }
}

vector<int> DBSCAN::regionQuery(Point point) {

    int index = 0;
    vector<int> cluster_index;

    vector<Point>::iterator db_iter;
    for(db_iter = pts.begin(); db_iter != pts.end(); db_iter++) {

        if(distanceMeasure(point, *db_iter) <= eps) {
            cluster_index.push_back(index);
        } 
    
        index++;
    }

    return cluster_index;
}

float DBSCAN::distanceMeasure(Point poi, Point target) {
    
    float square_sums = 0;

    for(int i = 0; i < dim; i++) {
        square_sums += pow(poi.point[i] - target.point[i], 2);
    }

    return sqrt(square_sums);
}

vector<Point> DBSCAN::getPoints() { 
    
    return pts;
}

int DBSCAN::getDimension() {
    return dim;
}

int DBSCAN::getClusterID(int index) {

    return pts.at(index).cluster_label;
}