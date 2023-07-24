
/*! Set variable species concentration. */
#define SET_VAR(ind_spec, qnt_Cspec) 			\
  if (ctl->qnt_Cspec >= 0)					\
    VAR[ind_spec] = atm->q[ctl->qnt_Cspec][ip];

/*! Get variable species concentration. */
#define GET_VAR(ind_spec, qnt_index)			\
  if (qnt_index >= 0)					\
    atm->q[qnt_index][ip] = VAR[ind_spec];

/*! Roeth approximation formula for photolysis reactions. */
#define ROETH_PHOTOL(a, b, c, sza) 				\
  (c*sza < M_PI/2. ? a * exp(b * (1 - 1/cos(c * sza))) : 0)

/*! Initialize concentration quantity. */
#define INIT_CQNT(qnt_index, clim_var_t)				\
  if (qnt_index >= 0)							\
    atm->q[qnt_index][ip] =						\
      clim_var(&clim_var_t, atm->time[ip], atm->lat[ip], atm->p[ip]);

void kpp_chem_bound_cond(
  ctl_t * ctl,
  atm_t * atm,
  met_t * met0,
  met_t * met1,
  int ip);

void kpp_chem_initialize(
  ctl_t * ctl,
  clim_t * clim,
  met_t * met0,
  met_t * met1,
  atm_t * atm,
  int ip);

void kpp_chem_output2atm(
  atm_t * atm,
  ctl_t * ctl,
  int ip);

void kpp_chemgrid_mass2concen(
  atm_t * atm,
  ctl_t * ctl,
  double *mass,
  double *area,
  int *ixs,
  int *iys,
  int *izs,
  double dz,
  int ip,
  int qnt_index);

void kpp_chem_init_cqnt(
  ctl_t * ctl,
  atm_t * atm,
	clim_t * clim,
  met_t * met0,
  met_t * met1,
  int ip);

double param_mixing_calc(
  ctl_t * ctl,
  clim_t * clim,
  atm_t * atm,
  int ip);

void interparc_mixing(
  ctl_t * ctl,
  atm_t * atm,
  clim_t * clim,
  int *ixs,
  int *iys,
  int *izs);

void interparc_mixing_help(
  ctl_t * ctl,
  atm_t * atm,
  clim_t * clim,
  int *ixs,
  int *iys,
  int *izs,
  int qnt_idx);