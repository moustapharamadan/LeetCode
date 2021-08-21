#pragma once
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>


namespace LEETCODE_1514 {
    class Solution {
    public:
        double maxProbability1(int n, std::vector<std::vector<int>>& edges, std::vector<double>& succProb, int start, int end) {
            std::vector<std::vector<double>> matrix(n,std::vector<double>(n,0));
            for (int k = 0; k < edges.size(); ++k)
            {
                int i = edges[k][0];
                int j = edges[k][1];
                matrix[i][j] = succProb[k];
                matrix[j][i] = succProb[k];
            }

            std::vector<int> unvisitedVertex(n);
            std::iota(unvisitedVertex.begin(), unvisitedVertex.end(), 0);
            unvisitedVertex.erase(std::find(unvisitedVertex.begin(), unvisitedVertex.end(), start));

            std::vector<double> maxProbability(n);
            for (int i = 0; i < n; ++i)
                maxProbability[i] = (start == i) ? 1 : 0;

            double probability = 1.;
            int currentVertex = start;
            while (!unvisitedVertex.empty())
            {
                for (const int vertex : unvisitedVertex)
                {
                    double tempProbability = probability * matrix[currentVertex][vertex];
                    if (maxProbability[vertex]<tempProbability)
                    {
                        maxProbability[vertex] = tempProbability;
                    }
                }

                double maxProb = -std::numeric_limits<double>::max();
                for (const int vertex : unvisitedVertex)
                {
                    if (maxProb < maxProbability[vertex])
                    {
                        maxProb = maxProbability[vertex];
                        currentVertex = vertex;
                    }
                }
                probability = maxProb;
                unvisitedVertex.erase(std::find(unvisitedVertex.begin(), unvisitedVertex.end(), currentVertex));
            }
            return maxProbability[end];
        }

        double maxProbability2(int n, std::vector<std::vector<int>>& edges, std::vector<double>& succProb, int start, int end) {
            std::vector<std::vector<double>> matrix(n, std::vector<double>(n, 0));
            for (int k = 0; k < edges.size(); ++k)
            {
                int i = edges[k][0];
                int j = edges[k][1];
                matrix[i][j] = succProb[k];
                matrix[j][i] = succProb[k];
            }

            std::vector<bool> shouldVisitVertex(n, true);
            shouldVisitVertex[start] = false;
            int remainingUnvisistedVertex = n - 1;

            std::vector<double> maxProbability(n);
            for (int i = 0; i < n; ++i)
                maxProbability[i] = (start == i) ? 1 : 0;

            double probability = 1.;
            int currentVertex = start;
            while (remainingUnvisistedVertex)
            {
                for (int vertex=0; vertex < n;++vertex)
                {
                    if (shouldVisitVertex[vertex])
                    {
                        double tempProbability = probability * matrix[currentVertex][vertex];
                        if (maxProbability[vertex] < tempProbability)
                        {
                            maxProbability[vertex] = tempProbability;
                        }
                    }
                }

                double maxProb = -std::numeric_limits<double>::max();
                for (int vertex = 0; vertex < n; ++vertex)
                {
                    if (shouldVisitVertex[vertex] && maxProb < maxProbability[vertex])
                    {
                        maxProb = maxProbability[vertex];
                        currentVertex = vertex;
                    }
                }
                probability = maxProb;
                --remainingUnvisistedVertex;
                shouldVisitVertex[currentVertex] = false;
            }
            return maxProbability[end];
        }


        double maxProbability(int n, std::vector<std::vector<int>>& edges, std::vector<double>& succProb, int start, int end) {
            std::vector<std::vector<double>> matrix(n, std::vector<double>(n, 0));
            for (int k = 0; k < edges.size(); ++k)
            {
                int i = edges[k][0];
                int j = edges[k][1];
                matrix[i][j] = succProb[k];
                matrix[j][i] = succProb[k];
            }

            std::vector<bool> shouldVisitVertex(n, true);
            shouldVisitVertex[start] = false;
            int remainingUnvisistedVertex = n - 1;

            std::vector<double> maxProbability(n);
            for (int i = 0; i < n; ++i)
                maxProbability[i] = (start == i) ? 1 : 0;

            double probability = 1.;
            int currentVertex = start;
            while (remainingUnvisistedVertex)
            {
                double maxProb = -std::numeric_limits<double>::max();
                int nextVertex = -1;
                for (int vertex = 0; vertex < n; ++vertex)
                {
                    if (shouldVisitVertex[vertex])
                    {
                        double tempProbability = probability * matrix[currentVertex][vertex];
                        if (maxProbability[vertex] < tempProbability)
                        {
                            maxProbability[vertex] = tempProbability;
                        }
                        if (maxProb < maxProbability[vertex])
                        {
                            maxProb = maxProbability[vertex];
                            nextVertex = vertex;
                        }
                    }
                }
                probability = maxProb;
                currentVertex = nextVertex;
                --remainingUnvisistedVertex;
                shouldVisitVertex[currentVertex] = false;

            }
            return maxProbability[end];
        }

    };
}