// -*- C++ -*-
// Scaffolding originally generated from include/server.x.
// Edit to add functionality.

#ifndef __XDR_SERVER_CACHESERVER_HH_INCLUDED__
#define __XDR_SERVER_CACHESERVER_HH_INCLUDED__ 1

#include "include/server.hh"
#include "include/rpcconfig.h"
#include "include/helpers.hh"
#include "include/httpclient.hh"
#include "lrucache.hh"

#include <vector>
#include <map>

class cache_api_v1_server {
private:
  lru_cache cache;
    
public:
  using rpc_interface_type = cache_api_v1;

  std::unique_ptr<bytestream> getCacheContents(std::unique_ptr<longstring> arg);
  std::unique_ptr<bytestream> getCacheContents2(std::unique_ptr<cacheRequest> arg);
  void newCacheserverAdded(std::unique_ptr<newCacheServerInfo> arg);
  void sendCachedData(std::unique_ptr<cacheTransfer> arg);
};

#endif // !__XDR_SERVER_CACHESERVERL_HH_INCLUDED__
