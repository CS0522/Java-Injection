/*
 * Copyright (c) 2020, Red Hat Inc.
 * ORACLE PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

package jdk.internal.platform;

/**
 * Marker interface for cgroup-based metrics
 *
 */
public interface CgroupSubsystem extends Metrics {

    /**
     * Returned for metrics of type long if the underlying implementation
     * has determined that no limit is being imposed.
     */
    public static final long LONG_RETVAL_UNLIMITED = -1;

}
