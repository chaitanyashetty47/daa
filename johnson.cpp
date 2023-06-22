#include<iostream>
#include <bits/stdc++.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
int num1;
class BellmanFord{
  public:
  vector<vector<int>>Graph;
  	 
    	int nodes;
        int src;
        bool cont=true;
    	multimap<int,pair<int,int>>map1;
    	multimap<int,pair<int,int>>map2;
        
    	// vector<int>visit;
  	 
    	map<int,pair<int,int>>ans;
	void Input(){
            	cout<<"enter the number of nodes"<<endl;
            	cin>>nodes;

            	int node1,node2;
            	vector<vector<int>>Graph(nodes+1,vector<int>(nodes+1,0));
            	do{
                    	cout<<"enter the nodes between which there is a edge"<<endl;
                    	cin>>node1>>node2;
                    	cout<<"enter the distance between them"<<endl;
                    	int dist;
                    	cin>>dist;
                    	if(dist==0)cont=false;
                    	else{
                            	Graph[node1][node2]=dist;
                            	map1.insert(pair<int,pair<int,int>>(dist,{node1,node2}));
                    	}
            	}while(cont);

            	for(int i=0;i<=nodes;i++){
                    	for(int j=1;j<=nodes;j++){
                            	if(Graph[i][j]!=0){
                                    	cout<<i<<"-->"<<j<<" is "<<Graph[i][j]<<endl;
                            	}
                    	}
            	}

                for(int i=0;i<nodes;i++){
                    map1.insert(pair<int,pair<int,int>>(0,{nodes,i}));
                }
    	}
   	 
    	void bellmanfunction(int new_src){
        	vector<int>dist1(nodes+1);
         	// cout<<"enter the number of the source node"<<endl;
         	// cin>>src;
         	
         	for(int i=0;i<nodes+1;i++){
                dist1[i]=INT_MAX;
            }
            dist1[new_src]=0;


            // for(int i=0;i<nodes;i++){
            //     map1[0]
            // }
            //uppar ki wajah se cont false hai;

            for(int i=0;i<nodes;i++){

                for(auto i=map1.begin();i!=map1.end();i++){
                    int s=i->second.first;
                    int d=i->second.second;
                    int travel=i->first;

                    if(dist1[s]!=INT_MAX && (dist1[s]+travel)<dist1[d]){
                        // cont=true;
                        dist1[d]=dist1[s]+travel;
                    }
                }

            }

            for(auto i=map1.begin();i!=map1.end();i++){
                    int s=i->second.first;
                    int d=i->second.second;
                    int travel=i->first;

                    if((dist1[s]+travel)<dist1[d]){
                        cont=true;
                        dist1[d]=dist1[s]+travel;
                    }
                }

        	 if(cont){
                cout<<"NEgative Cycle Detected "<<endl;
             }
             else{
                cout<<"The Shortest Path from the Source "<<new_src<<" is :"<<endl;

                
                    printf("Vertex   Distance from Source\n");
                        for(int i=0;i<nodes;i++){
                        printf("%d \t\t %d\n", i, dist1[i]);
                    }
                        cout<<endl;
             }


             for(auto i=map1.begin();i!=map1.end();i++){

                    int s=i->second.first;
                    int d=i->second.second;
                    int travel=i->first;

                    travel=travel+dist1[s]-dist1[d];
                    if(s!=nodes){
                        cout<<s<<"-->"<<d<<" "<<travel<<endl;
                    map2.insert(pair<int,pair<int,int>>(travel,{s,d}));
                    }    
            }

            // cout<<"map2 uppar wala "<<endl;
            //     for(auto i:map2){
            //     cout<<i.second.first<<" "<<i.second.second<<endl;
               
    	    // }
            //  cout<<"map2 uppar wala khatam"<<endl;

        }

        int minDist(vector<int>&dist,vector<bool>visit){
                int min=INT_MAX,index;
              
                    for(int i=0;i<dist.size();i++) 
                    {
                        if(visit[i]==false && dist[i]<=min)      
                        {
                            min=dist[i];
                            index=i;
                        }
                    }
                    return index;
        }



        void dijkstra(){
        vector<bool>visit(nodes);
        vector<int>dij_dist(nodes);

            vector<vector<int>>graph(nodes+1,vector<int>(nodes+1,0));


            for(auto i:map2){
                graph[i.second.first][i.second.second]=i.first;
            }

            //

            //     for(int i=0;i<nodes+1;i++){

            //         for(int j=0;j<nodes+1;j++){
            //             cout<<graph[i][j]<<" ";
            //         }
            //     cout<<endl;
            // }





            //
            // vector<vector<int>>MainAns(nodes+1,vector<int>(nodes+1,0));        idhar aaake dekhna jaroor

            // for(int op=0;op<nodes+1;op++){
            //     visit[op]=0;
            //     dij_dist[op]=INT_MAX;
            // }

        for(int i1=0;i1<nodes;i1++){

            for(int op=0;op<nodes;op++){
                visit[op]=false;
                dij_dist[op]=INT_MAX;
                
            }

            //first loop
            // cout<<"first loop"<<endl;
            //

                int dij_src=i1;
                dij_dist[i1]=0;

                for(int j=0;j<nodes;j++){
                    int m=minDist(dij_dist,visit);
                    // cout<<m<<endl;
                    visit[m]=true;

                    for(int i = 0; i<nodes; i++)                  
                        {
                            // Updating the minimum distance for the particular node.
                            if(!visit[i] && graph[m][i] && dij_dist[m]!=INT_MAX && dij_dist[m]+graph[m][i]<dij_dist[i])
                                dij_dist[i]=dij_dist[m]+graph[m][i];
                        }
                }
                cout<<"The shortest Distance from vertex :  "<<i1<<endl<<endl;
                for(int x=0;x<dij_dist.size();x++){
                    cout<<dij_dist[x]<<"     ";
                }
                cout<<endl;

            }

            // for(int i=0;i<nodes+1;i++){

            //     for(int j=0;j<nodes+1;j++){
            //         cout<<MainAns[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
        }
    
    
};


int main(){

     BellmanFord b;
    b.Input();
    cout<<"enter the number of nodes u have "<<endl;
    cin>>num1;
    b.bellmanfunction(num1);
    b.dijkstra();
	return 0;

    
    return 0;
}

