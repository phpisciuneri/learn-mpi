#include <iostream>
#include <random>
#include <mpi.h>

int main(int argc, char **argv) {

  if (argc < 2) {
    std::cerr << "Usage: pi <num_samples>" << std::endl;
    return 1;
  }

  int num_samples = std::stoi(argv[1]);

  int size, rank;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  std::default_random_engine generator(13);
  std::uniform_real_distribution<double> dist(0.0, 1.0);

  int count = 0;
  int my_count = 0;
  int my_samples = num_samples / size;
  for (int i=0; i<my_samples; i++) {
    double x = dist(generator);
    double y = dist(generator);
    if (std::sqrt(x * x + y * y) < 1.0) my_count++;
  }

  MPI_Allreduce(&my_count, &count, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

  double approx_pi = 4.0 * count / (my_samples * size);

  if (rank == 0) std::cout << approx_pi << std::endl;

  MPI_Finalize();

  return 0;
}