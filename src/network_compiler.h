//
// Created by Yujia Shen on 4/6/18.
//

#ifndef STRUCTURED_BN_NETWORK_COMPILER_H
#define STRUCTURED_BN_NETWORK_COMPILER_H
#include "network.h"
namespace structured_bn {
class NetworkCompiler {
 public:
  static NetworkCompiler *GetDefaultNetworkCompiler(Network *network);
  ~NetworkCompiler();
  PsddNode* Compile();
  // input must share the succedent vtree.
  static PsddNode *ConformLocalPsdd(Cluster *target_cluster,
                                    PsddManager *target_manager);
 private:
  explicit NetworkCompiler(Network *network, PsddManager *joint_psdd_manager);
  Network *network_;
  PsddManager *joint_psdd_manager_;
};
}
#endif //STRUCTURED_BN_NETWORK_COMPILER_H
