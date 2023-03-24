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

import java.io.BufferedReader;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.AccessController;
import java.security.PrivilegedActionException;
import java.security.PrivilegedExceptionAction;
import java.util.List;
import java.util.stream.Stream;

public final class CgroupUtil {

    public static Stream<String> readFilePrivileged(Path path) throws IOException {
        try {
            PrivilegedExceptionAction<Stream<String>> pea = () -> Files.lines(path);
            return AccessController.doPrivileged(pea);
        } catch (PrivilegedActionException e) {
            unwrapIOExceptionAndRethrow(e);
            throw new InternalError(e.getCause());
        } catch (UncheckedIOException e) {
            throw e.getCause();
        }
    }

    static void unwrapIOExceptionAndRethrow(PrivilegedActionException pae) throws IOException {
        Throwable x = pae.getCause();
        if (x instanceof IOException)
            throw (IOException) x;
        if (x instanceof RuntimeException)
            throw (RuntimeException) x;
        if (x instanceof Error)
            throw (Error) x;
    }

    static String readStringValue(CgroupSubsystemController controller, String param) throws IOException {
        PrivilegedExceptionAction<BufferedReader> pea = () ->
                Files.newBufferedReader(Paths.get(controller.path(), param));
        try (BufferedReader bufferedReader =
                     AccessController.doPrivileged(pea)) {
            String line = bufferedReader.readLine();
            return line;
        } catch (PrivilegedActionException e) {
            unwrapIOExceptionAndRethrow(e);
            throw new InternalError(e.getCause());
        } catch (UncheckedIOException e) {
            throw e.getCause();
        }
    }

    public static List<String> readAllLinesPrivileged(Path path) throws IOException {
        try {
            PrivilegedExceptionAction<List<String>> pea = () -> Files.readAllLines(path);
            return AccessController.doPrivileged(pea);
        } catch (PrivilegedActionException e) {
            unwrapIOExceptionAndRethrow(e);
            throw new InternalError(e.getCause());
        } catch (UncheckedIOException e) {
            throw e.getCause();
        }
    }
}
