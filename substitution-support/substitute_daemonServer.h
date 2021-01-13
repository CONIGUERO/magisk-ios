#ifndef	_substitute_daemon_server_
#define	_substitute_daemon_server_

/* Module substitute_daemon */

#include <string.h>
#include <mach/ndr.h>
#include <mach/boolean.h>
#include <mach/kern_return.h>
#include <mach/notify.h>
#include <mach/mach_types.h>
#include <mach/message.h>
#include <mach/mig_errors.h>
#include <mach/port.h>
	
/* BEGIN VOUCHER CODE */

#ifndef KERNEL
#if defined(__has_include)
#if __has_include(<mach/mig_voucher_support.h>)
#ifndef USING_VOUCHERS
#define USING_VOUCHERS
#endif
#ifndef __VOUCHER_FORWARD_TYPE_DECLS__
#define __VOUCHER_FORWARD_TYPE_DECLS__
#ifdef __cplusplus
extern "C" {
#endif
	extern boolean_t voucher_mach_msg_set(mach_msg_header_t *msg) __attribute__((weak_import));
#ifdef __cplusplus
}
#endif
#endif // __VOUCHER_FORWARD_TYPE_DECLS__
#endif // __has_include(<mach/mach_voucher_types.h>)
#endif // __has_include
#endif // !KERNEL
	
/* END VOUCHER CODE */

	
/* BEGIN MIG_STRNCPY_ZEROFILL CODE */

#if defined(__has_include)
#if __has_include(<mach/mig_strncpy_zerofill_support.h>)
#ifndef USING_MIG_STRNCPY_ZEROFILL
#define USING_MIG_STRNCPY_ZEROFILL
#endif
#ifndef __MIG_STRNCPY_ZEROFILL_FORWARD_TYPE_DECLS__
#define __MIG_STRNCPY_ZEROFILL_FORWARD_TYPE_DECLS__
#ifdef __cplusplus
extern "C" {
#endif
	extern int mig_strncpy_zerofill(char *dest, const char *src, int len) __attribute__((weak_import));
#ifdef __cplusplus
}
#endif
#endif /* __MIG_STRNCPY_ZEROFILL_FORWARD_TYPE_DECLS__ */
#endif /* __has_include(<mach/mig_strncpy_zerofill_support.h>) */
#endif /* __has_include */
	
/* END MIG_STRNCPY_ZEROFILL CODE */


#ifdef AUTOTEST
#ifndef FUNCTION_PTR_T
#define FUNCTION_PTR_T
typedef void (*function_ptr_t)(mach_port_t, char *, mach_msg_type_number_t);
typedef struct {
        char            *name;
        function_ptr_t  function;
} function_table_entry;
typedef function_table_entry   *function_table_t;
#endif /* FUNCTION_PTR_T */
#endif /* AUTOTEST */

#ifndef	substitute_daemon_MSG_COUNT
#define	substitute_daemon_MSG_COUNT	4
#endif	/* substitute_daemon_MSG_COUNT */

#include <mach/std_types.h>
#include <mach/mig.h>
#include <mach/mig.h>
#include <mach/mach_types.h>
#include "substituted-types.h"

#ifdef __BeforeMigServerHeader
__BeforeMigServerHeader
#endif /* __BeforeMigServerHeader */

#ifndef MIG_SERVER_ROUTINE
#define MIG_SERVER_ROUTINE
#endif


/* Routine substitute_setup_process */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t substitute_setup_process
(
	mach_port_t serverPort,
	pid_t target_pid,
	bool set_exec,
	bool should_resume,
	audit_token_t audit
);

/* Routine substitute_setup_self */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t substitute_setup_self
(
	mach_port_t serverPort,
	audit_token_t audit
);

/* Routine substitute_copy_extensions */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t substitute_copy_extensions
(
	mach_port_t serverPort,
	vm_task_entry_t task,
	mach_vm_address_t *stringAddress,
	mach_vm_size_t *stringSize,
	audit_token_t audit
);

/* Routine substitute_preflight */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
MIG_SERVER_ROUTINE
kern_return_t substitute_preflight
(
	mach_port_t serverPort,
	vm_task_entry_t task,
	mach_vm_address_t pathAddress,
	mach_vm_size_t pathSize,
	audit_token_t audit
);

#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
boolean_t substitute_daemon_server(
		mach_msg_header_t *InHeadP,
		mach_msg_header_t *OutHeadP);

#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
mig_routine_t substitute_daemon_server_routine(
		mach_msg_header_t *InHeadP);


/* Description of this subsystem, for use in direct RPC */
extern const struct substitute_daemon_subsystem {
	mig_server_routine_t	server;	/* Server routine */
	mach_msg_id_t	start;	/* Min routine number */
	mach_msg_id_t	end;	/* Max routine number + 1 */
	unsigned int	maxsize;	/* Max msg size */
	vm_address_t	reserved;	/* Reserved */
	struct routine_descriptor	/*Array of routine descriptors */
		routine[4];
} substitute_daemon_subsystem;

/* typedefs for all requests */

#ifndef __Request__substitute_daemon_subsystem__defined
#define __Request__substitute_daemon_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		pid_t target_pid;
		bool set_exec;
		char set_execPad[3];
		bool should_resume;
		char should_resumePad[3];
	} __Request__substitute_setup_process_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
	} __Request__substitute_setup_self_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t task;
		/* end of the kernel processed data */
	} __Request__substitute_copy_extensions_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		/* start of the kernel processed data */
		mach_msg_body_t msgh_body;
		mach_msg_port_descriptor_t task;
		/* end of the kernel processed data */
		NDR_record_t NDR;
		mach_vm_address_t pathAddress;
		mach_vm_size_t pathSize;
	} __Request__substitute_preflight_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif
#endif /* !__Request__substitute_daemon_subsystem__defined */


/* union of all requests */

#ifndef __RequestUnion__substitute_daemon_subsystem__defined
#define __RequestUnion__substitute_daemon_subsystem__defined
union __RequestUnion__substitute_daemon_subsystem {
	__Request__substitute_setup_process_t Request_substitute_setup_process;
	__Request__substitute_setup_self_t Request_substitute_setup_self;
	__Request__substitute_copy_extensions_t Request_substitute_copy_extensions;
	__Request__substitute_preflight_t Request_substitute_preflight;
};
#endif /* __RequestUnion__substitute_daemon_subsystem__defined */
/* typedefs for all replies */

#ifndef __Reply__substitute_daemon_subsystem__defined
#define __Reply__substitute_daemon_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__substitute_setup_process_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__substitute_setup_self_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
		mach_vm_address_t stringAddress;
		mach_vm_size_t stringSize;
	} __Reply__substitute_copy_extensions_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__substitute_preflight_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif
#endif /* !__Reply__substitute_daemon_subsystem__defined */


/* union of all replies */

#ifndef __ReplyUnion__substitute_daemon_subsystem__defined
#define __ReplyUnion__substitute_daemon_subsystem__defined
union __ReplyUnion__substitute_daemon_subsystem {
	__Reply__substitute_setup_process_t Reply_substitute_setup_process;
	__Reply__substitute_setup_self_t Reply_substitute_setup_self;
	__Reply__substitute_copy_extensions_t Reply_substitute_copy_extensions;
	__Reply__substitute_preflight_t Reply_substitute_preflight;
};
#endif /* __ReplyUnion__substitute_daemon_subsystem__defined */

#ifndef subsystem_to_name_map_substitute_daemon
#define subsystem_to_name_map_substitute_daemon \
    { "substitute_setup_process", 31337 },\
    { "substitute_setup_self", 31338 },\
    { "substitute_copy_extensions", 31339 },\
    { "substitute_preflight", 31340 }
#endif

#ifdef __AfterMigServerHeader
__AfterMigServerHeader
#endif /* __AfterMigServerHeader */

#endif	 /* _substitute_daemon_server_ */
