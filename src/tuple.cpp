/*
  Copyright (c) 2016 DataStax, Inc.

  This software can be used solely with DataStax Enterprise. Please consult the
  license at http://www.datastax.com/terms/datastax-dse-driver-license-terms
*/

#include "date_range.hpp"

CassError cass_tuple_set_dse_date_range(CassTuple* tuple,
                                        size_t index,
                                        const DseDateRange* range) {
  dse::Bytes bytes = dse::encode_date_range(range);
  return cass_tuple_set_custom(tuple, index, DSE_DATE_RANGE_TYPE,
                               bytes.data(), bytes.size());
}
