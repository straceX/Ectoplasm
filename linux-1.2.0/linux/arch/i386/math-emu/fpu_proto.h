/* errors.c */
extern void Un_impl(void);
extern void FPU_illegal(void);
extern void emu_printall(void);
extern void stack_overflow(void);
extern void stack_underflow(void);
extern void stack_underflow_i(int i);
extern void stack_underflow_pop(int i);
extern int set_precision_flag(int flags);
asmlinkage void exception(int n);
asmlinkage int real_2op_NaN(FPU_REG const *a, FPU_REG const *b, FPU_REG *dest);
asmlinkage int arith_invalid(FPU_REG *dest);
asmlinkage int divide_by_zero(int sign, FPU_REG *dest);
asmlinkage void set_precision_flag_up(void);
asmlinkage void set_precision_flag_down(void);
asmlinkage int denormal_operand(void);
asmlinkage int arith_overflow(FPU_REG *dest);
asmlinkage int arith_underflow(FPU_REG *dest);

/* fpu_arith.c */
extern void fadd__(void);
extern void fmul__(void);
extern void fsub__(void);
extern void fsubr_(void);
extern void fdiv__(void);
extern void fdivr_(void);
extern void fadd_i(void);
extern void fmul_i(void);
extern void fsubri(void);
extern void fsub_i(void);
extern void fdivri(void);
extern void fdiv_i(void);
extern void faddp_(void);
extern void fmulp_(void);
extern void fsubrp(void);
extern void fsubp_(void);
extern void fdivrp(void);
extern void fdivp_(void);

/* fpu_aux.c */
extern void fclex(void);
extern void finit(void);
extern void finit_(void);
extern void fstsw_(void);
extern void fp_nop(void);
extern void fld_i_(void);
extern void fxch_i(void);
extern void ffree_(void);
extern void ffreep(void);
extern void fst_i_(void);
extern void fstp_i(void);

/* fpu_entry.c */
asmlinkage void math_emulate(long arg);
extern void math_abort(struct info *info, unsigned int signal);

/* fpu_etc.c */
extern void fp_etc(void);

/* fpu_trig.c */
extern void convert_l2reg(long const *arg, FPU_REG *dest);
extern void trig_a(void);
extern void trig_b(void);

/* get_address.c */
extern void *get_address(unsigned char FPU_modrm, unsigned long *fpu_eip,
			 struct address *addr,
			 fpu_addr_modes);
extern void *get_address_16(unsigned char FPU_modrm, unsigned long *fpu_eip,
			    struct address *addr,
			    fpu_addr_modes);

/* load_store.c */
extern int load_store_instr(unsigned char type, fpu_addr_modes addr_modes,
			     void *address);

/* poly_2xm1.c */
extern int poly_2xm1(FPU_REG const *arg, FPU_REG *result);

/* poly_atan.c */
extern void poly_atan(FPU_REG *arg1, FPU_REG *arg2, FPU_REG *result);

/* poly_l2.c */
extern void poly_l2(FPU_REG const *arg, FPU_REG const *y, FPU_REG *result);
extern int poly_l2p1(FPU_REG const *arg, FPU_REG const *y, FPU_REG *result);

/* poly_sin.c */
extern void poly_sine(FPU_REG const *arg, FPU_REG *result);
extern void poly_cos(FPU_REG const *arg, FPU_REG *result);

/* poly_tan.c */
extern void poly_tan(FPU_REG const *arg, FPU_REG *result);

/* reg_add_sub.c */
extern int reg_add(FPU_REG const *a, FPU_REG const *b,
		   FPU_REG *dest, int control_w);
extern int reg_sub(FPU_REG const *a, FPU_REG const *b,
		   FPU_REG *dest, int control_w);

/* reg_compare.c */
extern int compare(FPU_REG const *b);
extern int compare_st_data(FPU_REG const *b);
extern void fcom_st(void);
extern void fcompst(void);
extern void fcompp(void);
extern void fucom_(void);
extern void fucomp(void);
extern void fucompp(void);

/* reg_constant.c */
extern void fconst(void);

/* reg_ld_str.c */
extern int reg_load_extended(long double *addr, FPU_REG *loaded_data);
extern int reg_load_double(double *dfloat, FPU_REG *loaded_data);
extern int reg_load_single(float *single, FPU_REG *loaded_data);
extern void reg_load_int64(long long *_s, FPU_REG *loaded_data);
extern void reg_load_int32(long *_s, FPU_REG *loaded_data);
extern void reg_load_int16(short *_s, FPU_REG *loaded_data);
extern void reg_load_bcd(char *s, FPU_REG *loaded_data);
extern int reg_store_extended(long double *d, FPU_REG *st0_ptr);
extern int reg_store_double(double *dfloat, FPU_REG *st0_ptr);
extern int reg_store_single(float *single, FPU_REG *st0_ptr);
extern int reg_store_int64(long long *d, FPU_REG *st0_ptr);
extern int reg_store_int32(long *d, FPU_REG *st0_ptr);
extern int reg_store_int16(short *d, FPU_REG *st0_ptr);
extern int reg_store_bcd(char *d, FPU_REG *st0_ptr);
extern int round_to_int(FPU_REG *r);
extern char *fldenv(fpu_addr_modes addr_modes, char *address);
extern void frstor(fpu_addr_modes addr_modes, char *address);
extern unsigned short tag_word(void);
extern char *fstenv(fpu_addr_modes addr_modes, char *address);
extern void fsave(fpu_addr_modes addr_modes, char *address);

/* reg_mul.c */
extern int reg_mul(FPU_REG const *a, FPU_REG const *b,
		   FPU_REG *dest, unsigned int control_w);
