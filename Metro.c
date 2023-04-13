#include <stdio.h>
#include <limits.h>

#define V 6

int min_distance(int dist[], int visited[])
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (visited[v] == 0 && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void display(int dist[])
{
	printf("Source City \t\t Distance from Source city\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t\t\t\t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	int visited[V];
	
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, visited[i] = 0;

	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = min_distance(dist, visited);
		visited[u] = 1;
		for (int v = 0; v < V; v++)
			if (!visited[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	display(dist);
}
int main()
{
	int graph[V][V] = {  {0,1120,1575,1748,1829,1898},
                          {1120,0,457,628,692,782,},
                          {1575,457,0,188,240,339},
                          {1748,628,188,0,213,165},
                          {1829,692,240,213,0,151},
                          {1898,782,339,165,157,0} };
	int s;
	printf("Where do you want to go ?\n");
    printf("Please choose your starting point from the below list.\n");
    printf("0.Kolkata\n1.Nagpur\n2.Aurangabad\n3.Nashik\n4.Pune\n5.Mumbai\n");

	scanf("%d",&s);
	dijkstra(graph, s);

	return 0;
}
