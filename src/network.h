//
// Created by Yujia Shen on 4/6/18.
//

#ifndef STRUCTURED_BN_NETWORK_H
#define STRUCTURED_BN_NETWORK_H
#include <string>
#include <vector>
#include "cluster.h"
namespace structured_bn {
class Network {
 public:
  static Network *GetNetworkFromSpecFile(const char *filename);
  // returns an arbitrary topological order. The root shows before leaves
  std::vector<Cluster *> ArbitraryTopologicalOrder() const;
  std::vector<Cluster *> RootClustersAfterCondition(const std::vector<Cluster *> &clusters_conditioned) const;
  const std::vector<Cluster *> &clusters() const;
  // returns 
  uint32_t cluster_size() const;
 private:
  Network(std::vector<std::string> variable_names,
          std::vector<Cluster *> clusters,
          std::vector<std::string> cluster_names);
  // indexed by 1
  std::vector<std::string> variable_names_;
  // indexed by 0
  std::vector<Cluster *> clusters_;
  std::vector<std::string> cluster_names_;
};
}
#endif //STRUCTURED_BN_NETWORK_H
