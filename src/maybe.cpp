#include <iostream>
#include <random>

#define BITS_PER_BYTE (8)

int main() {
  std::random_device random_device;
  std::mt19937_64 generator(random_device());
  std::uniform_int_distribution<unsigned int> distribution;

  char outputs[2] = { 'y', 'n' };

  if (random_device.entropy() == 0) {
    std::cerr << "Maybe: warning - non-deterministic random"
      " source not available" << std::endl;
  }
  
  while(std::cout.good()) {
    unsigned int random_uint = distribution(generator);
    for (unsigned int bit_idx = 0; bit_idx < sizeof(unsigned int) * BITS_PER_BYTE; ++bit_idx) {
      std::cout << outputs[!!(random_uint & (1 << bit_idx))] << '\n';
    }
    std::cout.flush();
  }

  if (std::cout.rdstate() & std::ostream::eofbit) {
    return 0;
  }

  std::cerr << "Maybe: error writing to output; aborting." << std::endl;
  return 1;
}
