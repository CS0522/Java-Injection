/*
 * $Id: ELJavascriptValidatorTagBeanInfo.java 471754 2006-11-06 14:55:09Z husted $
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
 * <code>org.apache.strutsel.taglib.html.ELJavascriptValidatorTag</code>
 * class. It is needed to override the default mapping of custom tag attribute
 * names to class attribute names. <p> This is because the value of the
 * unevaluated EL expression has to be kept separately from the evaluated
 * value, which is stored in the base class. This is related to the fact that
 * the JSP compiler can choose to reuse different tag instances if they
 * received the same original attribute values, and the JSP compiler can
 * choose to not re-call the setter methods, because it can assume the same
 * values are already set.
 */
public class ELJavascriptValidatorTagBeanInfo extends SimpleBeanInfo {
    public PropertyDescriptor[] getPropertyDescriptors() {
        ArrayList proplist = new ArrayList();

        try {
            proplist.add(new PropertyDescriptor("cdata",
                    ELJavascriptValidatorTag.class, null, "setCdataExpr"));
        } catch (IntrospectionException ex) {
        }

        try {
            proplist.add(new PropertyDescriptor("dynamicJavascript",
                    ELJavascriptValidatorTag.class, null,
                    "setDynamicJavascriptExpr"));
        } catch (IntrospectionException ex) {
        }

        try {
            proplist.add(new PropertyDescriptor("formName",
                    ELJavascriptValidatorTag.class, null, "setFormNameExpr"));
        } catch (IntrospectionException ex) {
        }

        try {
            proplist.add(new PropertyDescriptor("method",
                    ELJavascriptValidatorTag.class, null, "setMethodExpr"));
        } catch (IntrospectionException ex) {
        }

        try {
            proplist.add(new PropertyDescriptor("page",
                    ELJavascriptValidatorTag.class, null, "setPageExpr"));
        } catch (IntrospectionException ex) {
        }

        try {
            proplist.add(new PropertyDescriptor("scriptLanguage",
                    ELJavascriptValidatorTag.class, null,
                    "setScriptLanguageExpr"));
        } catch (IntrospectionException ex) {
        }

        try {
            proplist.add(new PropertyDescriptor("src",
                    ELJavascriptValidatorTag.class, null, "setSrcExpr"));
        } catch (IntrospectionException ex) {
        }

        try {
            proplist.add(new PropertyDescriptor("staticJavascript",
                    ELJavascriptValidatorTag.class, null,
                    "setStaticJavascriptExpr"));
        } catch (IntrospectionException ex) {
        }

        try {
            proplist.add(new PropertyDescriptor("htmlComment",
                    ELJavascriptValidatorTag.class, null, "setHtmlCommentExpr"));
        } catch (IntrospectionException ex) {
        }

        try {
            proplist.add(new PropertyDescriptor("bundle",
                    ELJavascriptValidatorTag.class, null, "setBundleExpr"));
        } catch (IntrospectionException ex) {
        }

        PropertyDescriptor[] result = new PropertyDescriptor[proplist.size()];

        return ((PropertyDescriptor[]) proplist.toArray(result));
    }
}
