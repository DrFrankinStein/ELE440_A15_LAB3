//Dijkstra(L[0..N-1,0..N-1],  Source,  Destination)  :  Chemin[0..N-1]  D[0..N-1], Visité[0..N-1], Chemin[0..N-1]
void Dijkstra(int L[][], int source, int Destination,  int N)
{
	int chemin[N];
	int D[N];
	int visited[N];
	int n;
	int visitedNumber;
	int closest;

	//Pour n = 0 à N-1
	for (n = 0; n < N; N++)
	{
		//D[n] = L[Source,n]
		D[n] = L[source][n];
		//Chemin[n] = Source
		chemin[n] = source;
		//Visité[n] = FAUX
		visited = false;
	}
	//Visité[Source] = VRAI
	visited = true;
	//nombreVisité = 1
	visitedNumber = 1;
	//Tant que nombreVisité < N
	while (visitedNumber < N)
	{
		//plusProche = sommet non visité avec le plus petit D
		closest = ;
		//Visité[plusProche] = VRAI
		visited[closest] = true;
		//nombreVisité = nombreVisité + 1
		visitedNumber = visitedNumber + 1;
	}
	//Pour tous les prochainSommet dans la liste des voisins de plusProche
	for ()
		//Si D[prochainSommet] > D[plusProche] + L[plusProche, prochainSommet]
		if (D[nextSummit] > D[closest] + L[closest, nextSummit])
		{
			//D[prochainSommet]  =  D[plusProche]  +  L[plusProche, prochainSommet]
			D[nextSummit] = D[closest] + L[closest][nextSummit];
	//Chemin[prochainSommet] = plusProche
	chemin[nextSummit] = closest
}
