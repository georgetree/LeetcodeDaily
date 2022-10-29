class LRUCache {
public:
    LRUCache(int capacity): capacity_(capacity) {}
    
    int get(int key) {
      auto it = m_.find(key);
      if (it == m_.end()) return -1;

      l_.splice(l_.begin(), l_, it->second);
      return it->second->second;
    }
    
    void put(int key, int value) {
      auto it = m_.find(key);
      if (it != m_.end()) {
        l_.erase(it->second);
      }
      l_.push_front(std::make_pair(key, value));
      m_[key] = l_.begin();

      if (m_.size() > capacity_) {
        int lastItemKey = l_.rbegin()->first;
        l_.pop_back();
        m_.erase(lastItemKey);
      }
    }
 private:
  int capacity_;
  std::list<std::pair<int, int>> l_;
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_;
};
