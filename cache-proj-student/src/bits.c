#include "cache.h"
#include "bits.h"

int get_set (Cache *cache, address_type address) {
  /* TODO:
     Extract the set bits from a 32-bit address.
   */
  int tagset= 32-cache->set_bits;
     
  return ((address >> (cache->block_bits)) << (tagset) >>(tagset)) ;
}

int get_line (Cache *cache, address_type address) {
  /* TODO:
     Extract the tag bits from a 32-bit address.
   */
  int together = ((cache->block_bits)+(cache->set_bits));
  int tag=32-together; 
  return address>>((cache->block_bits)+(cache->set_bits));
}

int get_byte (Cache *cache, address_type address) {
  /* TODO
     Extract the block (byte index) bits from a 32-bit address.
   */
  int together = ((cache->block_bits)+(cache->set_bits));
  int tag = (32-together) + cache->set_bits;

  return address << tag >> tag;
}
