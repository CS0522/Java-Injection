/*
 * $Id: ELOptionTagBeanInfo.java 479635 2006-11-27 14:27:18Z pbenedict $
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
package org.apache.strutsel.taglib.html;

import java.beans.IntrospectionException;
import java.beans.PropertyDescriptor;
import java.beans.SimpleBeanInfo;

import java.util.ArrayList;

/**
 * This is the <code>BeanInfo</code> descriptor for the
 * <code>org.apache.strutsel.taglib.html.ELOptionTag</code> class.  It is
 * needed to override the default mapping of custom tag attribute names to
 * class attribute names. <p> This is because the value of the unevaluated EL
 * expression has to be kept separately from the evaluated value, which is
 * stored in the base class. This is related to the fact that the JSP compiler
 * can choose to reuse different tag instances if they received the same
 * original attribute values, and the JSP compiler can choose to not re-call
 * the setter methods, because it can assume the same values are already set.
 */
public class ELOptionTagBeanInfo extends SimpleBeanInfo {
    public PropertyDescriptor[] getPropertyDescriptors() {
        ArrayList proplist = new ArrayList();

        try {
            proplist.add(new PropertyDescriptor("bundle", ELOptionTag.class,
                    null, "setBundleExpr"));
        } catch (IntrospectionException ex) {
        }

        try {
            proplist.add(new PropertyDescriptor("dir", ELOptionTag.class,
                    null, "setDirExpr"));
        } catch (IntrospectionException ex) {
        }

        try {
            proplist.add(new PropertyDescriptor("disabled", ELOptionTag.class,
                    null, "setDisabledExpr"));
        } catch (IntrospectionException ex) {
        }

        try {
            proplist.add(new PropertyDescriptor("filter", ELOptionTag.class, null,
                    "setFilterExpr"));
        } catch (IntrospectionException ex) {
        }

        try {
            proplist.add(new PropertyDescriptor("lang", ELOptionTag.class,
                    null, "setLangExpr"));
        } catch (IntrospectionException ex) {
        }

        try {
            proplist.add(new PropertyDescriptor("key", ELOptionTag.class, null,
                    "setKeyExpr"));
        } catch (IntrospectionException ex) {
        }

        try {
            proplist.add(new PropertyDescriptor("locale", ELOptionTag.class,
                    null, "setLocaleExpr"));
        } catch (IntrospectionException ex) {
        }

        try {
            proplist.add(new PropertyDescriptor("style", ELOptionTag.class,
                    null, "setStyleExpr"));
        } catch (IntrospectionException ex) {
        }

        try {
            proplist.add(new PropertyDescriptor("styleClass",
                    ELOptionTag.class, null, "setStyleClassExpr"));
        } catch (IntrospectionException ex) {
        }

        try {
            proplist.add(new PropertyDescriptor("styleId", ELOptionTag.class,
                    null, "setStyleIdExpr"));
        } catch (IntrospectionException ex) {
        }

        try {
            proplist.add(new PropertyDescriptor("value", ELOptionTag.class,
                    null, "setValueExpr"));
        } catch (IntrospectionException ex) {
        }

        PropertyDescriptor[] result = new PropertyDescriptor[proplist.size()];

        return ((PropertyDescriptor[]) proplist.toArray(result));
    }
}
