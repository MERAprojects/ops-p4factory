/*
Copyright 2013-present Barefoot Networks, Inc. 

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

//:: # Template file for fields C source
//:: # @fixme top matter needed
/*
 *
 * DO NOT EDIT:  This file is automatically generated.
 *
 * @fixme top matter
 *
 * Source code related to generic field support
 */

#include "enums.h"
#include "fields.h"
#include "phv.h"

#include <stdio.h>

//:: header_gen_objs = [				\
//::     ("bit_width", "int"),				\
//::     ("byte_offset_phv", "int"),			\
//::     ("num_fields", "int"),				\
//::     ("is_metadata", "int"),			\
//::     ("first_field", "rmt_field_instance_t"),	\
//::     ("byte_width_phv", "int"),			\
//:: ]
//::
//:: def gen_header_map_ref(obj_name, h_info, comma):
//::     width_str = "%-25s"
//::     if obj_name in ["bit_width", "byte_offset_phv", "byte_width_phv"]:
//::         width_str = "%-4s"
//::         obj_str = "-1" + comma  # Default if f_info is None
//::         if h_info: obj_str = str(h_info[obj_name]) + comma
//::     elif obj_name == "num_fields":
//::         width_str = "%-4s"
//::         obj_str = "-1" + comma  # Default if f_info is None
//::         if h_info: obj_str = str(len(h_info["fields"])) + comma
//::     elif obj_name == "is_metadata":
//::         width_str = "%-4s"
//::         obj_str = "0" + comma  # Default if f_info is None
//::         if h_info:
//::             obj_str = "1" if h_info["is_metadata"] else "0"
//::             obj_str += comma
//::         #endif
//::     elif obj_name == "first_field":
//::         obj_str = "RMT_FIELD_INSTANCE_NONE" + comma  # Default if f_info is None
//::         if h_info:
//::             obj_str = "RMT_FIELD_INSTANCE_" + h_info["fields"][0]
//::             obj_str += comma
//::         #endif
//::     #endif
//::     return width_str % obj_str
//:: #enddef

//:: for obj_name, ret_type in header_gen_objs:

/****************************************************************/


/*
 * Map from header instance to ${obj_name}
 */

${ret_type} _rmt_header_instance_${obj_name}[RMT_HEADER_INSTANCE_COUNT + 1] = {
  ${gen_header_map_ref(obj_name, None, ",")} /* RMT_HEADER_INSTANCE_NONE */
  //::     for header_instance in ordered_header_instances_virtual:
  ${gen_header_map_ref(obj_name, None, ",")} /* RMT_HEADER_INSTANCE_NONE */
  //::     #endfor
  //::     for header_instance in ordered_header_instances_non_virtual:
  //::         h_info = header_info[header_instance]
  ${gen_header_map_ref(obj_name, h_info, ",")} /* RMT_HEADER_INSTANCE_${header_instance} */
  //::     #endfor
  ${gen_header_map_ref(obj_name, None, "")} /* RMT_HEADER_INSTANCE_COUNT */
};
//:: #endfor

/*
 * Map from header instance back to name
 */

const char *rmt_header_instance_string[RMT_HEADER_INSTANCE_COUNT + 1] = {
  "INVALID (0)", /* NONE */
//:: for header_instance in ordered_header_instances_all:
  "${header_instance}",
//:: #endfor
  "INVALID (max)"
};


//:: # field_gen_objs is copied from fields.h template to track the objs
//:: field_gen_objs = [                                                 \
//::     ("bit_offset_hdr", "int"),                                     \
//::     ("bit_width", "int"),                                          \
//::     ("byte_offset_hdr", "int"),                                    \
//::     ("byte_offset_phv", "int"),                                    \
//::     ("byte_width_phv", "int"),                                     \
//::     ("data_type", "rmt_field_data_type_t"),                        \
//::     ("header", "rmt_header_instance_t"),                           \
//::     ("is_metadata", "int"),					\
//::     ("mask", "int"),                                               \
//:: ]
//::
//:: def gen_field_map_ref(obj_name, f_info, comma):
//::     width_str = "%-40s"
//::     if obj_name in ["bit_offset_hdr", "bit_width", "byte_offset_hdr", "byte_offset_phv", "byte_width_phv"]:
//::         width_str = "%-4s"
//::         obj_str = "-1" + comma  # Default if f_info is None
//::         if f_info: obj_str = str(f_info[obj_name]) + comma
//::     elif obj_name == "data_type":
//::         obj_str = "RMT_FIELD_DATA_TYPE_COUNT" + comma
//::         if f_info:
//::             dtype = f_info["data_type"][:-2]
//::             obj_str =  "RMT_FIELD_DATA_TYPE_" + dtype.upper() + comma
//::         #endif
//::     elif obj_name == "header":
//::         obj_str = "RMT_HEADER_INSTANCE_NONE" + comma
//::         if f_info:
//::             hdr = f_info["parent_header"]
//::             obj_str =  "RMT_HEADER_INSTANCE_" + hdr + comma
//::         #endif
//::     elif obj_name == "mask":
//::         width_str = "%-12s"
//::         obj_str = "0x0" + comma
//::         if f_info:
//::             obj_str = f_info["mask"] + comma
//::         #endif
//::     elif obj_name == "is_metadata":
//::         width_str = "%-4s"
//::         obj_str = "0" + comma  # Default if f_info is None
//::         if f_info:
//::             obj_str = "1" if f_info["is_metadata"] else "0"
//::             obj_str += comma
//::         #endif
//::     #endif
//::     return width_str % obj_str
//:: #enddef

//:: for obj_name, ret_type in field_gen_objs:

/****************************************************************/

/*
 * Map from field instance to ${obj_name}
 */

${ret_type} _rmt_field_instance_${obj_name}[RMT_FIELD_INSTANCE_COUNT + 1] = {
  ${gen_field_map_ref(obj_name, None, ",")} /* RMT_FIELD_INSTANCE_NONE */
  //::     for field_instance in ordered_field_instances_virtual:
  ${gen_field_map_ref(obj_name, None, ",")}
  //::     #endfor
  //::     for field_instance in ordered_field_instances_non_virtual:
  //::         f_info = field_info[field_instance]
  ${gen_field_map_ref(obj_name, f_info, ",")} /* RMT_FIELD_INSTANCE_${field_instance} */
  //::     #endfor
  ${gen_field_map_ref(obj_name, None, "")} /* RMT_FIELD_INSTANCE_COUNT */
};
//:: #endfor

/*
 * Map from field instance back to name
 */

const char *rmt_field_instance_string[RMT_FIELD_INSTANCE_COUNT + 1] = {
  "INVALID (0)", /* NONE */
//:: for field_instance in ordered_field_instances_all:
  "${field_instance}",
//:: #endfor
  "INVALID (max)"
};


void fields_print(phv_data_t *phv, rmt_field_instance_t field){
  rmt_field_data_type_t type = rmt_field_data_type(field);
  int phv_offset = rmt_field_byte_offset_phv(field);
  printf("field %s\n---->\t", rmt_field_instance_string[field]);
  if (type == RMT_FIELD_DATA_TYPE_UINT32) {
    printf("%x\n", ntohl(phv_buf_field_uint32_get(phv, phv_offset)));
  }
  else {
    uint8_t *buf = phv_buf_field_byte_buf_get(phv, phv_offset);
    int i;
    for(i = 0; i < rmt_field_byte_width_phv(field); i++)
      printf("%x\t", buf[i]);
    printf("\n");
  }
}

void *fields_get(phv_data_t *phv, rmt_field_instance_t field){
  int phv_offset = rmt_field_byte_offset_phv(field);
  return get_phv_ptr(phv, phv_offset);
}
