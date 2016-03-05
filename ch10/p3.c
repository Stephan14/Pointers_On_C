typedef union//使用无符号整数
{
  unsigned short addr;
  struct {
    unsigned opcode:10;
    unsigned
    unsigned
  } sgl_op;
  struct {
    unsigned
    unsigned
    unsigned
    unsigned
    unsigned
  } dbl_op;
  struct {
    unsigned
    unsigned
    unsigned
    unsigned
  } reg_src;
  struct {
    unsigned
    unsigned
  } branch;
  struct {
    unsigned
  } misc;
} machine_inst;
