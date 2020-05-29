#include "Algorithm.hpp"
#include "Controller.hpp"
// #include "testingFiles/ThreadTesting.hpp"


int main(){

	std::string pathToData = "KMeans/datasets/test.csv";


	KMeansAlgorithm kmRandomEuclid = KMeansAlgorithm(
		KMeans::KMeansBuilder{}\
		.setCentroindsInitializer(new RandomCentroindsInitializer())\
		.setMetrics(new EuclidDist)\
		.setData({pathToData})\
		.setK(8)\
		.build());
	KMeansAlgorithm kmRandomManhattan= KMeansAlgorithm(KMeans::KMeansBuilder{}\
		.setCentroindsInitializer(new RandomCentroindsInitializer())\
		.setMetrics(new ManhattanDist)\
		.setData({pathToData})\
		.setK(8)\
		.build());
	KMeansAlgorithm kmRandomChebyshev = KMeansAlgorithm(KMeans::KMeansBuilder{}\
		.setCentroindsInitializer(new RandomCentroindsInitializer())\
		.setMetrics(new ChebyshevDist)\
		.setData({pathToData})\
		.setK(8)\
		.build());
	KMeansAlgorithm kmRandomMinkowski = KMeansAlgorithm(KMeans::KMeansBuilder{}\
		.setCentroindsInitializer(new RandomCentroindsInitializer())\
		.setMetrics(new MinkowskiDist(4))\
		.setData({pathToData})\
		.setK(8)\
		.build());

	KMeansAlgorithm kmKFirstMinkowski = KMeansAlgorithm(KMeans::KMeansBuilder{}\
		.setCentroindsInitializer(new KFirstCentroindsInitializer())\
		.setMetrics(new MinkowskiDist(4))\
		.setData({pathToData})\
		.setK(8)\
		.build());
	KMeansAlgorithm kmKFirstChebyshev = KMeansAlgorithm(KMeans::KMeansBuilder{}\
		.setCentroindsInitializer(new KFirstCentroindsInitializer())\
		.setMetrics(new ChebyshevDist)\
		.setData({pathToData})\
		.setK(8)\
		.build());
	KMeansAlgorithm kmKFirstManhattan = KMeansAlgorithm(KMeans::KMeansBuilder{}\
		.setCentroindsInitializer(new KFirstCentroindsInitializer())\
		.setMetrics(new ManhattanDist)\
		.setData({pathToData})\
		.setK(8)\
		.build());
	KMeansAlgorithm kmKFirstEuclid = KMeansAlgorithm(KMeans::KMeansBuilder{}\
		.setCentroindsInitializer(new KFirstCentroindsInitializer())\
		.setMetrics(new EuclidDist)\
		.setData({pathToData})\
		.setK(8)\
		.build());

	KMeansAlgorithm kmLargestMinkowski = KMeansAlgorithm(KMeans::KMeansBuilder{}\
		.setCentroindsInitializer(new LargestCentroindsInitializer())\
		.setMetrics(new MinkowskiDist(4))\
		.setData({pathToData})\
		.setK(8)\
		.build());
	KMeansAlgorithm kmLargestChebyshev = KMeansAlgorithm(KMeans::KMeansBuilder{}\
		.setCentroindsInitializer(new LargestCentroindsInitializer())\
		.setMetrics(new ChebyshevDist)\
		.setData({pathToData})\
		.setK(8)\
		.build());
	KMeansAlgorithm kmLargestManhattan = KMeansAlgorithm(KMeans::KMeansBuilder{}\
		.setCentroindsInitializer(new LargestCentroindsInitializer())\
		.setMetrics(new ManhattanDist)\
		.setData({pathToData})\
		.setK(8)\
		.build());
	KMeansAlgorithm kmLargestEuclid = KMeansAlgorithm(KMeans::KMeansBuilder{}\
		.setCentroindsInitializer(new LargestCentroindsInitializer())\
		.setMetrics(new EuclidDist)\
		.setData({pathToData})\
		.setK(8)\
		.build());
	
	std::vector<Algorithm*> kmeansAlgorithms { 
		&kmRandomEuclid, &kmRandomManhattan, &kmRandomChebyshev, &kmRandomMinkowski,\
		&kmKFirstMinkowski, &kmKFirstChebyshev, &kmKFirstManhattan, &kmKFirstManhattan,\
		&kmLargestMinkowski, &kmLargestChebyshev, &kmLargestManhattan, &kmLargestEuclid 
	};

	std::vector<std::string> resulsPATHS

	{
		"kmRandomEuclid.csv", 	"kmRandomManhattan.csv", "kmRandomChebyshev.csv", "kmRandomMinkowski.csv",\
		"kmKFirstMinkowski.csv", "kmKFirstChebyshev.csv", "kmKFirstManhattan.csv", "kmKFirstManhattan.csv",\
		"kmLargestMinkowski.csv", "kmLargestChebyshev.csv", "kmLargestManhattan.csv", "kmLargestEuclid.csv"\
	};

	std::string resultDir = "KMeans/results/";
	for (int i = 0; i < resulsPATHS.size(); ++i)
		resulsPATHS[i] = resultDir + resulsPATHS[i];

	ThreadController<8, Algorithm*> controller;
  	controller.push(kmeansAlgorithms, resulsPATHS).start();


	return 0;
}
