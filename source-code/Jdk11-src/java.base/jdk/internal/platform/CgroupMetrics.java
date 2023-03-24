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

import java.util.Objects;

public class CgroupMetrics implements Metrics {

    private final CgroupSubsystem subsystem;

    CgroupMetrics(CgroupSubsystem subsystem) {
        this.subsystem = Objects.requireNonNull(subsystem);
    }

    @Override
    public String getProvider() {
        return subsystem.getProvider();
    }

    @Override
    public long getCpuUsage() {
        return subsystem.getCpuUsage();
    }

    @Override
    public long[] getPerCpuUsage() {
        return subsystem.getPerCpuUsage();
    }

    @Override
    public long getCpuUserUsage() {
        return subsystem.getCpuUserUsage();
    }

    @Override
    public long getCpuSystemUsage() {
        return subsystem.getCpuSystemUsage();
    }

    @Override
    public long getCpuPeriod() {
        return subsystem.getCpuPeriod();
    }

    @Override
    public long getCpuQuota() {
        return subsystem.getCpuQuota();
    }

    @Override
    public long getCpuShares() {
        return subsystem.getCpuShares();
    }

    @Override
    public long getCpuNumPeriods() {
        return subsystem.getCpuNumPeriods();
    }

    @Override
    public long getCpuNumThrottled() {
        return subsystem.getCpuNumThrottled();
    }

    @Override
    public long getCpuThrottledTime() {
        return subsystem.getCpuThrottledTime();
    }

    @Override
    public long getEffectiveCpuCount() {
        return subsystem.getEffectiveCpuCount();
    }

    @Override
    public int[] getCpuSetCpus() {
        return subsystem.getCpuSetCpus();
    }

    @Override
    public int[] getEffectiveCpuSetCpus() {
        return subsystem.getEffectiveCpuSetCpus();
    }

    @Override
    public int[] getCpuSetMems() {
        return subsystem.getCpuSetMems();
    }

    @Override
    public int[] getEffectiveCpuSetMems() {
        return subsystem.getEffectiveCpuSetMems();
    }

    public long getMemoryFailCount() {
        return subsystem.getMemoryFailCount();
    }

    @Override
    public long getMemoryLimit() {
        return subsystem.getMemoryLimit();
    }

    @Override
    public long getMemoryUsage() {
        return subsystem.getMemoryUsage();
    }

    @Override
    public long getTcpMemoryUsage() {
        return subsystem.getTcpMemoryUsage();
    }

    @Override
    public long getMemoryAndSwapLimit() {
        return subsystem.getMemoryAndSwapLimit();
    }

    @Override
    public long getMemoryAndSwapUsage() {
        return subsystem.getMemoryAndSwapUsage();
    }

    @Override
    public long getMemorySoftLimit() {
        return subsystem.getMemorySoftLimit();
    }

    @Override
    public long getBlkIOServiceCount() {
        return subsystem.getBlkIOServiceCount();
    }

    @Override
    public long getBlkIOServiced() {
        return subsystem.getBlkIOServiced();
    }

    public static Metrics getInstance() {
        if (!isUseContainerSupport()) {
            // Return null on -XX:-UseContainerSupport
            return null;
        }
        return CgroupSubsystemFactory.create();
    }

    private static native boolean isUseContainerSupport();

}
